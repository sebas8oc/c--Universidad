#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int vf;
	int n;
	int cp = 0;
	int ci = 0;
	int sp = 0;
	int si = 0;
	
	
	cout << "Cuantos numeros desea guardar: ";
	cin >> vf;
	
	for (int i = 1; i <= vf; i++) {
		
		cout << "Digite numeros: ";
		cin >> n;
		
		if (n % 2 == 0) {
			cp += 1;
			sp = sp + n;
		} else {
			ci += 1;
			si = si + n;
		}
	}
		
	cout << endl << " Pares ingresados: " << cp;
	cout << endl << " Suma de Pares ingresados: " << sp;
	cout << endl << " Impares ingresados: " << ci;
	cout << endl << " Suma de Impares ingresados: " << si;
	
	return 0;
}
