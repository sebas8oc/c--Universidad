#include <iostream>
#include <time.h>
using namespace std;


#define Tam 3

int main(int argc, char *argv[]) {
	
	bool listo = false;
	int arreglo[Tam];
	int opc;
	
	do {
		
		cout << endl << " 1. Guardar Datos \n 2. Mostrar Datos \n 3. Salir";
		cout << endl << "\n Digita tu opcion: ";
		cin >> opc;
		
		switch (opc) {
			case 1:
				
				for (int x = 0; x < Tam; x++) {
					cout << endl << "\n Digite un dato: ";
					cin >> arreglo[x];
				}
				
				listo = true;
				
			break;
		
			case 2:
				
				if (listo == true) {
					for (int x = 0; x < Tam; x++) {
						cout << " " << arreglo[x] << " ";
					}
				} else {
					cout << endl << "\n Primero debe de ir a la opcion 1 y llenar el arreglo con enteros";
				}
				
				
			break;
			
		default: if ( opc != 3) { cout << "opcion invalida"; }
			
		}
		
		
		
	} while(opc != 3);
	
	return 0;
}
