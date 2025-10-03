
// librerias de entrada y salida
#include <iostream>

// libreria para manejo de strings
#include <string>

using namespace std;

int main() {

  // arreglo bidimensional de strings
  string mi_clase[3][4];

  // int test01 = size(mi_clase);  // 3
  // int test = size(mi_clase[0]); // 4

  // llenar el arreglo bidimensional con strings
  cout << "Ingrese los nombres de los estudiantes de la clase\n";
  for (int j = 0; j < size(mi_clase); j++) {
    for (int i = 0; i < size(mi_clase[0]); i++) {
      cin >> mi_clase[j][i];
    }
  }

  // imprimir el arreglo bidimensional con strings
  cout << "Los nombres de los estudiantes de la clase son: " << endl;
  for (int j = 0; j < size(mi_clase); j++) {
    for (int i = 0; i < size(mi_clase[0]); i++) {
      cout << mi_clase[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}