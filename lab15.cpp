#include <iostream>

// Libreria para usar size()
// Se puede usar tambien sizeof() pero es mas complicado

// Si no se coloca esta libreria puede que el compilador
// la agregue automaticamente pero no es seguro
#include <iterator>

using namespace std;

int main() {

  cout << "Introduce el nombre de 6 compañeros de clase: " << endl;
  string names[6];
  int i = 0;

  for (i; i < size(names); i++) {
    cin >> names[i];
  }
  i = 0;

  printf("++++++++++++++++++\n");
  printf("Los nombres de tus compañeros son: \n");

  do {
    cout << names[i] << " ";
    i++;
  } while (i < size(names));

  // salto de linea al final para mejor presentacion
  cout << endl;

  return 0;
}