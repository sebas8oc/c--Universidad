// Quiz Sebastian Otero Cruz

#include <iostream>
using namespace std;

#define Tam 8
#define Tom 6
#define Tim 5


int main(int argc, char *argv[]) {
	
	int opc = 4;
	int array[Tam];
	int nu, mayor, menor, cp = 0, ci = 0;
	float notas[Tim], nota,  suma = 0, promedio = 0;
	
	do {
		cout << endl << "\n 1. Encontrar n < y > \n 2. Contdor pares e impares \n 3. Promedio de notas \n 4. Salir ";
		cout << endl << "\n Digite su opcion (1,2,3,4): ";
		cin >> opc;
			
		switch(opc) {
			
		case 1:
			
			// pide 8 numeros y muestra el menor y el mayor
		
			for (int i = 0; i < Tam; i ++) {
				cout << endl << "\n Digite un numero: ";
				cin >> nu;
				array[i] = nu;
			}
			
			mayor = 0;
		
			for (int i = 0; i < Tam; i ++) {
				if (array[i] > mayor) {
					mayor = array[i];
				}
			}
			
			menor = array[0];
			
			for (int i = 0; i <= Tam; i ++) {
				if (array[i] < menor) {
					menor = array[i];
				}
			}
			
			cout << "\n";
			
			for (int i = 0; i < Tam; i ++) {
				cout << " " << array[i] << " ";
			}
			
			cout << endl << "\n Numero mayor = " << mayor << "\n Numero menor = " << menor;
			
		break;
		
		case 2:
			
			// solicita 6 numeros los guarda en un arreglo cuenta pares e impares y muestra
			
			for (int i = 0; i < Tom; i ++) {
				cout << endl << "\n Digite un numero: ";
				cin >> nu;
				array[i] = nu;
			}
			
			for (int i = 0; i < Tom; i ++) {
				if (array[i] % 2 == 0) {
					cp ++;
				} else {
					ci ++;
				}
			}
			
			cout << "\n";
			
			for (int i = 0; i < Tom; i ++) {
				cout << " " << array[i] << " ";
			}
			
			cout << endl << "\n Contador pares: " << cp << "\n Contador impares: " << ci;
			
		break;
		
		case 3:
			
			// solicita 5 notas(float) calcula promedio si es >= 3 aprueba sino reprueba
			
			for (int i = 0; i < Tim; i ++) {
				cout << endl << "\n Digite un numero flotante del 1 al 5: ";
				cin >> nota;
				if (nota >= 1 && nota <= 5) {
					notas[i] = nota;
				} else {
					i--;
				}
			}
			
			cout << "\n";
			
			for (int i = 0; i < Tim; i ++) {
				suma = notas[i] + suma;
				cout << " " << notas[i] << " ";
			}
			
			promedio = suma / Tim;
			
			if (promedio >= 3.0) {
				cout << endl << "\n Su nota fue: " << promedio << " APROBO ";
			} else {
				cout << endl << "\n Su nota fue: " << promedio << " REPROBO ";
			}
		
			
		break;
			
		case 4:
			
			cout << endl << "\n SALIENDO...";
			
		break;
		
		default: cout << endl << "\n OPCION INVALIDA";
		}
	} while(opc != 4);
	
	return 0;
}
