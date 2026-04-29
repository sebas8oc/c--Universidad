#include <iostream>
#include <time.h>
using namespace std;

#define Uno 4
#define Dos 4


int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int cp = 0, cf = 0;
	int opc, c, n;
	bool igual = false;
	int ale;
	int pf;
	int adivinar[Uno];
	int usuario[Dos];
	
	adivinar[0] = rand() % 10;
	
	for (int i = 1; i < Uno; i ++) {
		ale = rand() % 10;
		for (int j = 0; j < i; j ++) {
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
	
	do {
		cout << endl << "\n 1. Jugar 2. Salir\n";
		cout << endl << "Digita Opcion: ";
		cin >> opc;
		
		switch (opc) {
		case 1:
			do {
				cout << endl << "\nTiene 10 oportunidades para adivinar";
				for (int i = 0; i < Dos; i++) {
					cout << endl << "Digita uno por uno los numeros: ";
					cin >> n;
					for (int j = 0; j < i; j ++) {
						if (usuario[j] == n) {
							igual = true;
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
				
				for(int i = 0;i < Uno; i ++) {
					int a = adivinar[i];
					for (int j = 0; j < Dos; i ++) {
						if (usuario[i] == a) {
							cf += 1;
							break;
						} 
					}
				}
				
				for(int i = 0;i < Uno; i ++) {
					int a = adivinar[i];
					for (int j = 0; j < Dos; i ++) {
						if (usuario[i] == a) {
							cf += 1;
							break;
						} 
					}
				}
				
				for(int i = 0; i < Uno; i ++) {
					for (int j = 0; j < Dos; j ++) {
						
					}
				}
				
				for (int j = 0; j < Dos; j++){
					cout  << " " << usuario[j] << " ";
				}
				cout << endl << "\n Fijas: " << cf;
				
				
			} while(c < 10);
		break;
		case 2:
			cout << endl  << "\n       Saliendo......";
		break;
		default: cout << endl << "Opcion invalida";
		}
		
	} while(opc != 2);
	
	return 0;
}
