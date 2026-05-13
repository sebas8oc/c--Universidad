#include <iostream>
using namespace std;

void RecibirDatos(string &, int &);
void Felicitacion(string, int);

int main() {
	
	string Nombre;
	int Edad;
	
	RecibirDatos(Nombre, Edad);
	Felicitacion(Nombre, Edad);
	return 0;
}

void Felicitacion(string Nombre, int Edad) {
	cout << endl << "Felicitaciones " << Nombre << " por sus " << Edad;
}

void RecibirDatos(string &Nombre, int &Edad) {
	cout << endl << " Cual es su Nombre: ";
	cin >> Nombre;
	cout << endl << " Cual es su Edad: ";
	cin >> Edad;
}
