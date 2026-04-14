#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int opc;
	int e;
	cout << endl << "-----MENU----- \n 1. ";
	cout << "Digite un una opcion: ";
	cin >> opc;
	
	switch(opc){
	case 1:
		cout << "1";
		break;
	case 2:
		cout << "2";
		break;
	default: cout << "OPCION INVALIDA";
		break;
	}
	return 0;
}

