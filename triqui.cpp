#include <iostream>
using namespace std;

#define Tam 4

void llenarTriqui(string triqui[Tam][Tam]);
void mostrarTriqui(string triqui[Tam][Tam]);
void pedirNombres(string &name1, string &name2);

int main() {

  string triqui[Tam][Tam], name1, name2;
  bool gano = false;
  int opc, x, y, turno = 1;

  llenarTriqui(triqui);

  do {

    cout << endl << " 1. Jugar 2. Salir ";
    cout << endl << " Digite la opcion: ";
    cin >> opc;

    switch (opc) {
    case 1:

      pedirNombres(name1, name2);

      do {

        mostrarTriqui(triqui);

        if (turno % 2 == 0) {
          cout << endl
               << " Juega " << name1 << " con [x] digite las coordenadas";
          cout << endl << " x: ";
          cin >> x;
          cout << endl << " y: ";
          cin >> y;
          if (triqui[x][y] == "[]") {
            triqui[x][y] = "X";
          } else {
            cout << endl << " Coordenada Invalida ";
            turno--;
          }
        } else {
          cout << endl
               << " Juega " << name2 << " con [O] digite las coordenadas";
          cout << endl << " x: ";
          cin >> x;
          cout << endl << " y: ";
          cin >> y;
          if (triqui[x][y] == "[]") {
            triqui[x][y] = "O";
          } else {
            cout << endl << " Coordenada Invalida ";
            turno--;
          }
        }

        turno++;
      } while (gano == false && turno != 10);
      break;
    default:
      cout << endl << " OPCION INCOMODA ";
      break;
    }

  } while (opc != 2);

  return 0;
}

void llenarTriqui(string triqui[Tam][Tam]) {
  triqui[0][1] = "1", triqui[0][2] = "2", triqui[0][3] = "3",
  triqui[1][0] = "1", triqui[2][0] = "2", triqui[3][0] = "3";

  for (int i = 1; i < Tam; i++) {
    for (int j = 1; j < Tam; j++) {
      triqui[i][j] = "[]";
    }
  }
}

void mostrarTriqui(string triqui[Tam][Tam]) {
  for (int i = 0; i < Tam; i++) {
    cout << endl;
    for (int j = 0; j < Tam; j++) {
      cout << triqui[i][j] << "\t";
    }
  }
  cout << endl;
}

void pedirNombres(string &name1, string &name2) {
  cout << endl << " Digite el nombre del Jugador 1: ";
  cin >> name1;

  cout << endl << " Digite el nombre del Jugador 2: ";
  cin >> name2;
}
