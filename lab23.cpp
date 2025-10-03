// librerias de entrada y salida
#include <iostream>

// libreria para manejo de strings
#include <string>

using namespace std;

// definir una estructura para almacenar nombre y edad
struct Student {
  string name;
  int age;
};

int main() {

  Student NameAge[2][6];

  // variables para pruebas de size
  // int test01 = size(NameAge); // 2
  // int test = size(NameAge[0]); // 6

  // variable para contar estudiantes
  int c = 1;

  // llenar el arreglo bidimensional con estructuras
  cout << "Ingrese los nombres y edades de los estudiantes de la clase" << endl;
  for (int j = 0; j < size(NameAge); j++) {
    for (int i = 0; i < size(NameAge[0]); i++) {

      cout << "Inserte el nombre del estudiante " << (c++) << ": ";
      cin >> NameAge[j][i].name;
      cout << "Inserte la edad de " << NameAge[j][i].name << ": ";
      cin >> NameAge[j][i].age;
      cout << endl;
    }
  }

  // imprimir mensaje de busqueda de nombre

  cout << "\ningrese el nombre a buscar" << endl;

  // variable para buscar nombre
  string nameToFind;

  //  variable para indicar si se encontro el nombre
  bool found = false;

  //  leer el nombre a buscar
  cin >> nameToFind;

  // buscar el nombre en el arreglo bidimensional
  // si se encuentra imprimir la edad
  // si no se encuentra imprimir mensaje de no encontrado
  // usar la variable found para indicar si se encontro el nombre
  // al finalizar la busqueda si found es false imprimir mensaje de no
  // encontrado
  for (int j = 0; j < size(NameAge); j++) {
    for (int i = 0; i < size(NameAge[0]); i++) {
      if (NameAge[j][i].name == nameToFind) {
        cout << "Edad de " << NameAge[j][i].name << " es: " << NameAge[j][i].age
             << endl;
        found = true;
      }
    }
  }

  // si no se encontro el nombre imprimir mensaje de no encontrado
  if (found != true) {
    cout << "No se encontro el nombre" << endl;
  }

  return 0;
}