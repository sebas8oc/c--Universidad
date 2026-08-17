#include <iostream>
using namespace std;

// Dos vectores 
// char
// 1. con el nombre
// 2. con el apellido
// declaramos
// otro tercer vector guardamos el contenido del primer vector y el segundo y lo imprimimos

int main(int argc, char *argv[]) {
	
	char nombre[10] = {'S','e','b','a','s','t','i','a','n',' '};
	char apellido[5] = {'O','t','e','r','o'};
	char nCompleto[15];
	
	for (int i = 0; i < 11; i++) {
		nCompleto[i] = nombre[i];
	}
	
	for (int i = 0; i < 16; i++) {
		nCompleto[i+10] = apellido[i];
	}
	
	for (int i = 0; i < 15; i++) {
		cout << nCompleto[i];
	}
	
	return 0;
}
