#include <iostream>
#include <time.h>
using namespace std;


#define Tam 10

int main(int argc, char *argv[]) {
	
	bool par = false;
	bool superior = false;
	float promedio;
	float s = 0;
	int n;
	
	srand(time(NULL));
	
	int arreglo[Tam];
	
	for (int x = 0; x < Tam; x++) {
		arreglo[x]= rand()%100;
		if (arreglo[x] % 2 == 0) {
			par = true;
		}
		if (arreglo[x] > 90) {
			superior = true;
		}
	}
	
	for (int x = 0; x < Tam; x++) {
		s += arreglo[x];
		cout << arreglo[x] << " ";
	
	}
	
	promedio = s / 30;
	cout << "El promedio del arreglo es = " << promedio;
	
	if(par == true){
		cout << endl << "al menos uno de los numeros es par";
	} else {
		cout << endl << "No hay pares";
	}
	
	if(superior == true){
		cout << endl << "al menos uno de los numeros es > 90";
	} else {
		cout << endl << "No hay ningun numero mayor a 90";
	}
	
	return 0;
}
