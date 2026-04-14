#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int vi;
	int vf;
	//int t;
	
	cout << "Digite vi: ";
	cin >> vi;
	
	cout << "Digite vf: ";
	cin >> vf;
	
	if (vi > vf) {
		t = vf;
		vf = vi;
		vi = t;
	}
	
	for (int i = vi  ; i  <= vf; i++)	{
		cout << endl << i;
	}
	
	return 0;
}
