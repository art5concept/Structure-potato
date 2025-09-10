#include <iostream>
#include <iterator>

using namespace std;

int main() {

  int table[100] = {};
  // Ciclo para llenar el arreglo de los numeros del 100 al 1
  for (int i = 0; i < size(table); i++) {
    table[i] = 100 - i;
  }
  // Ciclo para imprimir el arreglo
  for (int i = 0; i < size(table); i++) {
    cout << table[i] << endl;
  }
  return 0;
}