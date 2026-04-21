#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int saldo = 0;
	int consignado;
	int opc;
	
	do {
		
		cout << endl << " 1. Consultar Saldo \n 2. Retirar (Validar Saldo) \n 3. Consignar \n 4. Salir \n ";
		cout << endl << " Digite su opcion: ";
		cin >> opc;
		
		switch(opc) {
		case 1: 
			
			cout << endl << " Su saldo es de $ " << saldo << " COP";	
			
		break;
		
		case 2:
			
			if (saldo > 0) {
				cout << endl << " Saldo actual $ " << saldo << " COP";
				cout << endl << " Cuanto dinero desea  retirar: ";
				cin >> consignado;
				if (saldo = saldo - consignado > 0) {
					cout << endl << " Su retiro es de:  " << saldo << " COP";
					saldo = saldo - consignado;
					cout << endl << " Saldo actual $ " << saldo << " COP";
				} else {
					cout << endl <<  "Ingrese un valor valido no tiene esa cantidad de dinero";
				}
				
			} else {
				cout << endl << " No tiene Saldo  !!!! ";
			}
			
		break;
			
		case 3: 
			
			cout << endl << " Cuanto dinero desea  consignar: ";
			cin >> consignado;
			saldo = saldo + consignado;
		break;
		
		default: cout << endl << "OPC INVALIDA";
		}
		
	} while(opc != 4);
	
	
	return 0;
} 
