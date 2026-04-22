#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int vi, vf, t;
	int nm, nu, ni = 0, ci = 0;
	
	cout << endl <<  "Con cuantos intentos va a jugar: \n";
	cin >> ni;

	cout << endl <<  "Digita vi: \n";
	cin >> vi;
	
	cout << endl <<  "Digita vf: \n";
	cin >> vf;
	
	
	if (vi > vf) {
		t = vf;
		vf = vi;
		vi = t;
	}
	
	nm = rand()%(vf - vi + 1) + vi;
	
	do {
		cout << endl <<  "Adivina el numero magico: \n";
		cin >> nu;
		
		ci ++;
		
		if (nu == nm && ci < ni) {
			cout << endl << ":) FELICITACIONES ADIVINASTE EL NUMERO MAGICO \n";
			cout << endl << "Ganaste en " << ci << " intentos";
		} else if (nu < nm) {
			cout << endl  << ":( El numero magico es mas alto \n";
		} else if (nu > nm) {
			cout << endl << ":( El numero magico es mas bajo \n";
		}
		
	} while(ni != ci && nu != nm);
	
	if (ni == ci) {
		cout << " PERDISTE \n";
		cout << " \n intentos: " << ci;
		cout << " \n oportunidades: " << ni;
	}
	
	return 0;
}
