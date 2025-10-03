// librerias de entrada y salida
#include <iostream>

// libreria para manejo de strings
#include <string>

using namespace std;

int main() {

  // arreglo bidimensional de strings
  string mi_clase[3][4];

  // introduccion de datos al arreglo bidimensional con strings
  cout << "Ingrese los nombres de los estudiantes de la clase\n";
  for (int i = 0; i < size(mi_clase); i++) {
    for (int j = 0; j < size(mi_clase[0]); j++) {
      cin >> mi_clase[i][j];
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
  // imprimir mensaje de busqueda de nombre
  cout << "\ningrese el nombre a buscar" << endl;
  // variable para buscar nombre
  string nameToFind;
  bool found = false;
  cin >> nameToFind;

  // buscar el nombre en el arreglo bidimensional
  // si se encuentra cambiar el nombre por el string introducido como apellido
  // si no se encuentra imprimir mensaje de no encontrado
  // usar la variable found para indicar si se encontro el nombre
  // al finalizar la busqueda si found es false imprimir mensaje de no
  // encontrado
  for (int j = 0; j < size(mi_clase); j++) {
    for (int i = 0; i < size(mi_clase[0]); i++) {
      if (mi_clase[j][i] == nameToFind) {
        cout << "Cambiando nombre de " << mi_clase[j][i]
             << " por el apellido: " << endl;
        cout << "Inserte el apellido de " << mi_clase[j][i] << ": ";
        cin >> mi_clase[j][i];
        found = true;
      }
    }
  }

  // mensaje si no se encontro el nombre
  if (found != true) {
    cout << "No se encontro el nombre" << endl;
  }

  // imprimir el arreglo bidimensional con strings
  cout << "Los nombres de los estudiantes de la clase son diferentes" << endl;
  for (int j = 0; j < size(mi_clase); j++) {
    for (int i = 0; i < size(mi_clase[0]); i++) {
      cout << mi_clase[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}