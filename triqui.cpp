  if (contador == 3)
    gano = true;
}

void GanoO(string triqui[][Tam], bool &gano, int &contador) {

  // Revisar Filas
  for (int i = 0; i < Tam; i++) {
    contador = 0;
    for (int j = 0; j < Tam; j++) {
      if (triqui[i][j] == "O") {
        contador++;
        if (contador == 3) {
          gano = true;
        }
      }
    }
  }

  // Revisar Columnas
  for (int i = 0; i < Tam; i++) {
    contador = 0;
    for (int j = 1; j < Tam; j++) {
      if (triqui[j][i] == "O") {
        contador++;
        if (contador == 3) {
          gano = true;
        }
      }
    }
  }

  // Digonal
  contador = 0;
  for (int i = 1; i < Tam; i++) {
    if (triqui[i][i] == "O")
      contador++; // i==j siempre en la diagonal
  }
  if (contador == 3)
    gano = true;

  // Diagonal inversa ↙
  contador = 0;
  for (int i = 1; i < Tam; i++) {
    if (triqui[i][Tam - i] == "O")
      contador++; // [1][3], [2][2], [3][1]
  }
  if (contador == 3)
    gano = true;
}
