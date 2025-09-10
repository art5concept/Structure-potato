#include <iostream>
#include <iterator>

using namespace std;

int main() {
  // inicializacion de variables y arreglo con 10 espacios
  int i = 0;
  int table[10] = {};

  printf("Entra 10 numeros:\n");
  while (i < size(table)) {
    cin >> table[i];
    i++;
  }

  int suma = 0, resta = 0;
  int multiplicacion = 1;

  // Ciclo para sumar, restar y multiplicar los numeros del arreglo
  for (int i = 0; i < size(table); i++) {

    suma += table[i];
    resta -= table[i];
    multiplicacion *= table[i];
  }

  printf("La suma es: %d\n", suma);
  printf("La resta es: %d\n", resta);
  printf("La multiplicacion es: %d\n", multiplicacion);

  return 0;
}