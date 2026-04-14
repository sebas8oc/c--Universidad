#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int opc;
	int n1, n2, r;
	
	cout << endl << " ----- MENU ----- \n 1.Suma \n 2.Restar \n 3.Multiplicar \n 4.Dividir \n";
	
	cout << endl << "Digite un una opcion: ";
	cin >> opc;
	
	if (opc >= 1 && opc <= 4){
		cout << "Digite x: ";
		cin >> n1;
		
		cout << "Digite y: ";
		cin >> n2;
	}
	
	switch(opc){
	case 1:
		r = n1 * n2;
		cout << endl << r;
		break;
	case 2:
		r = n1 - n2;
		cout << endl << r;
		break;
	case 3:
		r = n1 * n2;
		cout << endl << r;
		break;
	case 4:
		if (n2 != 0) {
			r = n1 / n2;
			cout << endl << r;
			cout << endl << " --------- ERROR --------- ";
		}
		break;
	default: cout << endl << "OPCION INVALIDA ";
		break;
	}
	
	return 0;
}
