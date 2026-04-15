#include <iostream>
#include <time.h>
using namespace std;

int main () {

  srand(time(NULL));
  
  int vf;
  int opc;
  int bajos;
  int g = 0;
  int p = 0;
  int te = 0;
  int tg = 0;
  int tp = 0;
  int dado;

  do {
    g = 0;
    p = 0;
    cout << endl << "------MENU------\n 1. Jugar 2. Salir\n";
    cout << endl << " Digite opcion: ";
    cin >> opc;
    
    if (opc == 1) {
      
      cout << endl << "Cuantas veces desea jugar: ";
      cin >> vf;
      
      cout << endl << " Desea jugar con bajoss (1-3) o altas (4-6)\n";
      cout << endl << " Digite 1 para bajoss y 2 para altas: ";
      cin >> bajos;

      if (bajos == 1) {
        for (int i = 1; i <= vf; i++) {
          if (p == vf) {
            tp += 1;
          }
          dado = rand()%(6 - 1 + 1) + 1;
          cout << endl << " El jugador eligio bajos \n";
          cout << endl << " Lanzando dados... \n";
          cout << endl << " Resultado del dado: " << dado << "\n";
          if (dado > 3) {
            cout << endl << " Perdio ronda " << i << "\n";
            p += 1;
          } else {
            cout << endl << " Gano ronda " << i << "\n";
            g += 1;
          }
          cout << endl << " Rondas ganadas: " << g << " Rondas perdidas: " << p << "\n";
        }
        if ( vf % 2 == 0) {
          if ( g == p ) {
            te += 1;
            cout << endl << " Resutltado de la partida EMPATE\n";
            cout << endl << " Total de empates " << te;
          } else if ( g > p ) {
            tg += 1;
            cout << endl << " Resultado de la partida GANO\n";
            cout << endl << " Total de Victorias " << tg;
          } else {
            tp += 1;
            cout << endl << " Resultado de la partida PERDIO\n";
              cout << endl << " Total de perdidas " << tp;
          }
        } else {
          if ( g > p ) {
            tg += 1;
            cout << endl << " Resultado de la partida GANO\n";
            cout << endl << " Total de Victorias " << tg;
          } else {
            tp += 1;
            cout << endl << " Resultado de la partida PERDIO\n";
              cout << endl << " Total de perdidas " << tp;
          }

        }
      } else if (bajos == 2) {
         for (int i = 1; i <= vf; i++) {
          if (p == vf) {
            tp += 1;
          }
          dado = rand()%(6 - 1 + 1) + 1;
          cout << endl << "El jugador eligio bajos \n";
          cout << endl << "Lanzando dados... \n";
          cout << endl << "Resultado del dado: " << dado;
          if (dado < 4) {
            cout << endl << "Perdio ronda " << i;
            p += 1;
          } else {
            cout << endl << "Gano ronda " << i;
            g += 1;
          }
          cout << endl << "Rondas ganadas: " << g << " Rondas perdidas: " << p;
        }
      } else if ( bajos != 1 || bajos != 2   ) {
        cout << endl << "Opcion invalida ";
      }
        
    }

  } while(opc != 2);


  return 0;
}
