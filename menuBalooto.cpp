#include <iostream>
#include <time.h>

using namespace std;

#define Uno 5
#define Dos 5

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int vi = 1, vf = 5;
	int vfb = 16;
	
	bool igual = false;
	
	int aUno[Uno];
	int ados[Dos];
	int opt, t;
	int ng,no, ngd;
	int bgu, bgd;
	
	aUno[0] = rand()%(vf - vi + 1) + vi;
	
	do {
		
		cout << endl << "\n 1. Jugar \n 2. Salir \n";
		cout << endl << "\n Digite su opcion: ";
		cin >> opt;
		
		switch(opt) {
		case 1:
			for (int i = 1; i < Uno; i ++) {
				ng = rand()%(vf - vi + 1) + vi;
				for (int j = 0; j < i; j ++) {
					if (aUno[j] == ng) {
						igual = true;
						break;
					}
				}
			if (igual) {
				i--;
			} else {
				aUno[i] = ng;
			}
			igual = false;
			}
			
			for (int i = 1; i < Dos; i ++) {
				ng = rand()%(vf - vi + 1) + vi;
				for (int j = 0; j < i; j ++) {
					if (ados[j] == ng) {
						igual = true;
						break;
					}
				}
				if (igual) {
					i--;
				} else {
					ados[i] = ng;
				}
				igual = false;
			}
			
			
		
			for (int i = 0; i < Uno; i ++) {
				cout << endl << " Primer Baloto : " << aUno[i] << " ";
			}
			
		break;
		case 2:
			cout << "Saliendo";
		break;
		default: cout << "opc invalida";
		}
		
		
	} while(opt != 2);
	
	return 0;
}

