#include <iostream>
#include <time.h>
using namespace std;

#define filas 10
#define cols 7
#define Tam 4
#define Tom 2

int main() {

  int opc, ale, u, cf = 0, cp = 0, ci = 0, intento = 0;

  bool repetido, gano = false;

  int adivinar[Tam], jugador[Tam], historial[filas][cols];

  srand(time(NULL));

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < cols; j++) {
      historial[i][j] = 0;
    }
  }

  do {
    cout << endl
         << "\n ------ MENU ------ \n 1. Jugar 2. Salir \n Digita tu opcion: ";

    cin >> opc;

    switch (opc) {
    case 1:
      // Genera el numero aleatorio apenas el jugador elige la opc 1

      for (int i = 0; i < Tam; i++) {

        do {
          repetido = false;

          ale = rand() % 10;

          for (int j = 0; j < i; j++) {

            if (ale == adivinar[j]) {
              repetido = true;
            }
          }
        } while (repetido);

        adivinar[i] = ale;
      }

      // IMPRIME EL NUMERO A ADIVINAR
      for (int i = 0; i < Tam; i++) {
        cout << adivinar[i];
      }

      cout << endl;

      do {
        cf = 0;
        cp = 0;
        // Suma 1 al numero de intentos
        intento++;
        // genera los 4n aleatorios sin repetir
        //

        // PIDE EL NUMERO AL USUARIO
        for (int i = 0; i < Tam; i++) {
          do {
            repetido = false;

            cout << endl << "digita un #: ";
            cin >> u;

            if (u > 9 || u < 0) {
                cout << endl << "Numero invalido \n";
            }
            
            for (int j = 0; j < i; j++) {
                if (u == jugador[j]) {
                    cout << endl << "Numero repetido \n";
                    repetido = true;
                }
            }
          } while (repetido);

          historial[ci][i + 1] = u;
          jugador[i] = u;
        }
        
        historial[ci][0] = intento;

        // CUENTA PICAS Y filas

        for (int i = 0; i < Tam; i++) {
          if (adivinar[i] == jugador[i]) {
            cf++;
            cp--;
          }
          for (int j = 0; j < Tam; j++) {
            if (adivinar[i] == jugador[j]) {
              cp++;
            }
          }
        }
        historial[ci][6] = cf;
        historial[ci][5] = cp;
        ci++;

        cout << endl << "HISTORIAL";
        cout << endl << "I\t*\t*\t*\t*\tP\tF";
        for (int i = 0; i < filas; i++) {
          cout << endl;
          for (int j = 0; j < cols; j++) {
            cout << historial[i][j] << "\t";
          }
        }

        cout << endl;

        if (historial[9][0] > 0) {
          for (int i = 9; i < filas; i++) {
            for (int j = 0; j < cols; j++)
              for (int k = 0; k < 1; k++) {
                for (int l = 0; l < cols; l++) {
                  historial[k][l] = historial[i][j];
                }
              }
          }

          for (int m = 1; m < filas; m++) {
            for (int n = 0; n < cols; n++) {
              historial[m][n] = 0;
            }
          }
        }

        // Revisar si gano
        if (cf == 4) {
          gano = true;
          cout << endl << "Felicidades Ganaste";
        }

      } while (gano == false);

      break;

    case 2:

      cout << endl << "SALIENDO...";
      break;

    default:
      cout << endl << "----- ERROR OPCION INVALIDA -----";
      break;
    }

  } while (opc != 2);

  return 0;
}
