#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	int vector[4];
	int nu;
	
	for (int i = 0; i < 4; i++) {
		cout << "Digite el numero a ingresar en el arreglo: ";
		cin >> nu;
		vector[i] = nu;
		
	}
	
	for (int i = 0; i < 4; i++) {
		cout << vector[i];
		
	}
	
	return 0;
}

