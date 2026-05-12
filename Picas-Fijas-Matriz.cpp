#include <iostream>
using namespace std;

#define Tam 3

int main(int argc, char *argv[]) {
	
	bool lleno = false;
	
	int array[Tam][Tam];
	
	int opc;
	
	do {
		system("cls");
		cout << endl << " MENU \n 1. Ingresar datos \n 2. Mostrar datos \n 3. Salir \n ingrese una opcion:  ";
		cin >> opc;
		
		switch (opc) {
		case 1:
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j ++) {
					cout << "ingrese un dato: ";
					cin >> array[i][j];
				}
			}
			
			lleno = true;
			break;
			
		case 2:
			if (lleno) {
				cout <<  "C1\tC2\tC3\t";
				for (int i = 0; i < Tam; i++) {
					cout << endl;
					for (int j = 0; j < Tam; j ++) {
						
						cout << array[i][j] << "\t";
					}
				}
			} else {
				cout << endl << "Priemero debe de ingreaser datos";
			}
			
			break;
			
		case 3:
			cout << "SALIENDO ... SALIENDO ... SALIENDO...";
			break;
			
		default: cout << endl << "OPCION INCORRECTA";
		}
		system("pause");
	} while(opc != 3);
	
	return 0;
}

