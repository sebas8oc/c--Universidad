#include <iostream>
using namespace std;

#define Tam 2
#define Tom 3

int main(int argc, char *argv[]) {

  int nu;
  int array[Tam][Tom];

  for (int i = 0; i < Tam; i++) {
    for (int j = 0; j < Tom; j++) {
      cout << "Digite #: ";
      cin >> nu;
      array[i][j] = nu;
    }
  }

  for (int i = 0; i < Tam; i++) {
    cout << endl;
    for (int j = 0; j < Tom; j++) {
      cout << array[i][j];
    }
  }

  return 0;
}
