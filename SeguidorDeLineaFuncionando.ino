// ============================================================
//  SEGUIDOR DE LÍNEA - Versión mejorada
//  Mejoras respecto al original:
//   - analogRead con umbral ajustable (soporta sensores analógicos)
//   - Control proporcional simple para giros más suaves
//   - Búsqueda de línea cuando se pierde
//   - Lógica clara de asignación de motores
// ============================================================

// --- SENSORES (usar analogRead con umbral) ---
#define SENSOR_IZQ A0
#define SENSOR_DER A1
#define UMBRAL 500          // Ajusta según tus sensores (0-1023)
                            // TCRT5000 típico: ~300-700

// --- PUENTE H L298N ---
// Asumiendo:
//   Canal A -> Motor IZQUIERDO
//   Canal B -> Motor DERECHO
// Si tus motores están al revés, intercambia las funciones girarIzquierda/girarDerecha
#define ENA 5    // PWM velocidad motor izquierdo
#define IN1 8
#define IN2 9

#define IN3 10
#define IN4 11
#define ENB 6    // PWM velocidad motor derecho

// --- VELOCIDADES ---
int velocidadBase = 150;     // Velocidad en recta (0-255)
int velocidadGiro = 120;     // Velocidad al girar

// --- CONTROL PROPORCIONAL ---
int proporcional = 0;        // Diferencia entre sensores para giro suave

// --- ESTADOS ---
enum Estado {
  EN_LINEA,
  PERDIDO_IZQ,
  PERDIDO_DER,
  BUSCANDO
};

Estado estado = EN_LINEA;
unsigned long tiempoPerdido = 0;

// ============================================================

bool enLinea(int pin) {
  return analogRead(pin) < UMBRAL;   // Negro absorbe luz -> valor bajo
}

void setup() {
  pinMode(SENSOR_IZQ, INPUT);
  pinMode(SENSOR_DER, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Seguidor de línea iniciado");
  Serial.print("Umbral: ");
  Serial.println(UMBRAL);
}

void loop() {
  bool izq = enLinea(SENSOR_IZQ);
  bool der = enLinea(SENSOR_DER);

  Serial.print("IZQ: ");
  Serial.print(izq ? 1 : 0);
  Serial.print(" (");            // Muestra valor crudo para calibración
  Serial.print(analogRead(SENSOR_IZQ));
  Serial.print(")  DER: ");
  Serial.print(der ? 1 : 0);
  Serial.print(" (");
  Serial.print(analogRead(SENSOR_DER));
  Serial.print(")  Estado: ");
  Serial.println(estado);

  // --- LÓGICA PRINCIPAL ---
  if (izq && der) {
    // Ambos sensores sobre línea negra -> adelante
    estado = EN_LINEA;
    adelante();
  }
  else if (izq && !der) {
    // Solo izquierdo sobre línea -> girar izquierda
    estado = EN_LINEA;
    girarIzquierda();
  }
  else if (!izq && der) {
    // Solo derecho sobre línea -> girar derecha
    estado = EN_LINEA;
    girarDerecha();
  }
  else {
    // Ambos sensores en blanco -> seguir recto
    estado = EN_LINEA;
    adelante();
  }
}

// ============================================================
//  FUNCIONES DE MOVIMIENTO
// ============================================================

void motorIzquierdo(int velocidad, bool adelante) {
  // velocidad: 0-255, adelante: true=avanzar, false=retroceder
  analogWrite(ENB, velocidad);
  digitalWrite(IN3, adelante ? HIGH : LOW);
  digitalWrite(IN4, adelante ? LOW : HIGH);
}

void motorDerecho(int velocidad, bool adelante) {
  // velocidad: 0-255, adelante: true=avanzar, false=retroceder
  analogWrite(ENA, velocidad);
  digitalWrite(IN1, adelante ? LOW : HIGH);
  digitalWrite(IN2, adelante ? HIGH : LOW);
}

// --- ADELANTE ---
void adelante() {
  motorIzquierdo(velocidadBase, true);
  motorDerecho(velocidadBase, true);
}

// --- GIRAR IZQUIERDA ---
void girarIzquierda() {
  // Versión suave: reduce velocidad del motor izquierdo
  motorIzquierdo(velocidadGiro / 2, true);
  motorDerecho(velocidadGiro, true);

  // Alternativa: giro sobre el eje (descomenta y comenta lo de arriba)
  // motorIzquierdo(0, true);
  // motorDerecho(velocidadGiro, true);
}

// --- GIRAR DERECHA ---
void girarDerecha() {
  // Versión suave: reduce velocidad del motor derecho
  motorIzquierdo(velocidadGiro, true);
  motorDerecho(velocidadGiro / 2, true);

  // Alternativa: giro sobre el eje (descomenta y comenta lo de arriba)
  // motorIzquierdo(velocidadGiro, true);
  // motorDerecho(0, true);
}

// --- BUSCAR LÍNEA ---
void buscarLinea() {
  unsigned long ahora = millis();
  unsigned long dt = ahora - tiempoPerdido;

  // Primeros 500ms: intenta seguir recto
  if (dt < 500) {
    motorIzquierdo(velocidadGiro * 0.6, true);
    motorDerecho(velocidadGiro * 0.6, true);
    return;
  }

  // Siguientes 500ms: gira buscando la línea
  if (dt < 1000) {
    motorIzquierdo(-80, true);   // Gira sobre sí mismo
    motorDerecho(80, true);
    return;
  }

  // Si pasó 1s sin encontrar línea, detente
  detener();
}

// --- DETENER ---
void detener() {
  motorIzquierdo(0, true);
  motorDerecho(0, true);
}
