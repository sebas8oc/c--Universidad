#include <iostream>
#include <time.h>
using namespace std;

#define Uno 4
#define Dos 4

int main() {

  srand(time(NULL));

  bool gano = false;
  int cp = 0, cf = 0;
  int opc, c = 0, n;
  bool igual = false, menor = false;
  int ale;
  int adivinar[Uno];
  int usuario[Dos];
  int opt = 10;

  do {
    adivinar[0] = rand() % 10;

    for (int i = 1; i < Uno; i++) {
      ale = rand() % 10;
      for (int j = 0; j < i; j++) {
        if (adivinar[j] == ale) {
          igual = true;
          break;
        }
      }
      if (igual) {
        i--;
      } else {
        adivinar[i] = ale;
      }
      igual = false;
    }

    for (int i = 0; i < Uno; i++) {
      cout << " " << adivinar[i] << " ";
    }

    cout << endl << "\n 1. Jugar 2. Salir\n";
    cout << endl << "Digita Opcion: ";
    cin >> opc;

    switch (opc) {
    case 1:
      do {
        cout << endl << "\nTiene " << opt << " oportunidades para adivinar";
        for (int i = 0; i < Dos; i++) {
          cp = 0, cf = 0;
          cout << endl << "Digita uno por uno los numeros: ";
          cin >> n;

          if (n < 0 || n > 9) {
            cout << " Numero fuera de rango, debe ser entre 0 y 9." << endl;
            i--;
            continue;
          }

          for (int j = 0; j < i; j++) {
            if (usuario[j] == n) {
              igual = true;
              break;
            }
            if (n < 0 || n > 9) {
              menor = true;
              break;
            }
          }
          if (igual) {
            i--;
          } else {
            usuario[i] = n;
          }
          igual = false;
        }

        opt--;
        c++;

        for (int i = 0; i < Uno; i++) {
          if (usuario[i] == adivinar[i]) {
            cf++;
            cp--;
          }
          for (int t = 0; t < Uno; t++) {
            if (usuario[i] == adivinar[t]) {
              cp++;
            }
          }
        }

        cout << endl << " *  *  *  *" << endl;
        for (int j = 0; j < Dos; j++) {
          cout << " " << usuario[j] << " ";
        }
        cout << endl << "\n Fijas: " << cf;
        cout << endl << "\n Picas: " << cp;

        if (cf == 4) {
          gano = true;
          cout << endl << "\n Felicidades ganasete en " << c << " intentos";
        }

      } while (c < 10 && gano == false);
      break;
    case 2:
      cout << endl << "\n       Saliendo......";
      break;
    default:
      cout << endl << "Opcion invalida";
    }

  } while (opc != 2);

  return 0;
}
