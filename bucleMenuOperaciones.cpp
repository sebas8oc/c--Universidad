#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int opc;
	int n1, n2, r;
	
	for (int x = 0; x < 3; x++){
		cout << endl << " Hello world ";
	}
	
	do {
		cout << endl << " ----- MENU ----- \n 1.Suma \n 2.Restar \n 3.Multiplicar \n 4.Dividir \n 5. Salir";
		
		cout << endl << "Digite un una opcion: ";
		cin >> opc;
		
		
		
		switch(opc){
		case 1:
			cout << "Digite x: ";
			cin >> n1;
			
			cout << "Digite y: ";
			cin >> n2;
			
			r = n1 + n2;
			cout << endl << r;
			break;
		case 2:
			cout << "Digite x: ";
			cin >> n1;
			
			cout << "Digite y: ";
			cin >> n2;
			
			r = n1 - n2;
			cout << endl << r;
			break;
		case 3:
			cout << "Digite x: ";
			cin >> n1;
			
			cout << "Digite y: ";
			cin >> n2;
			
			r = n1 * n2;
			cout << endl << r;
			break;
		case 4:
			cout << "Digite x: ";
			cin >> n1;
			
			cout << "Digite y: ";
			cin >> n2;
			
			if (n2 != 0) {
				r = n1 / n2;
				cout << endl << r;
				
			} else { 
				cout << endl << " --------- ERROR --------- ";
			}
			break;
		default: 
		break;
		}
	} while( opc != 5);
	
	return 0;
}
