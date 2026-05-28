#define SENSOR_IZQ A0
#define SENSOR_DER A1

#define ENA 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENB 6

int velocidad = 150;

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
}

void loop() {

  int izq = digitalRead(SENSOR_IZQ);
  int der = digitalRead(SENSOR_DER);

  Serial.print("IZQ: ");
  Serial.print(izq);

  Serial.print(" DER: ");
  Serial.println(der);

  // ambos negros
  if (izq == 0 && der == 0) {
    adelante();
  }

  // izquierda detecta línea
  else if (izq == 0 && der == 1) {
    girarIzquierda();
  }

  // derecha detecta línea
  else if (izq == 1 && der == 0) {
    girarDerecha();
  }

  // perdió línea
  else {
    detener();
  }
}

void adelante() {

  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarIzquierda() {

  analogWrite(ENA, 0);
  analogWrite(ENB, velocidad);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarDerecha() {

  analogWrite(ENA, velocidad);
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void detener() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
