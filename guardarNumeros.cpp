#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int vf;
	int par;
	int n;
	int i;
	
	
	cout << "Cuantos numeros desea guardar ";
	cin >> vf;
	
	cout << "Quiere guardar pares o impares? 1 = Pares / 2 = Impares: ";
	cin >> par;
	
	
	switch(par) {
		case 1:

			for (i = 1; i <= vf; i++) {
				
				cout << endl << i<<" Digite un numero par\n";
				cin >> n;
				
				if ( n % 2 == 0) {
					cout << endl << "Guardando... \n";
					
				} else {
					cout << "No es par";
				}
			}
		break;
			
		case 2:
				
			for (int i = 1; i <= vf;) {
					
				cout << endl << "Digite un numero par\n";
				cin >> n;
					
				if ( n % 2 == 1) {
					cout << endl << "Guardando... \n";
					i++;
				} else { 
					cout << "No es impar";
				}
			}
		break;
	default: cout << "Opcion invalida";
	}
	
	return 0;
}
