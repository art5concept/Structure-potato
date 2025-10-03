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

  // arreglo bidimensional de estructuras para alamacenar nombre y edad
  Student NameAge[2][6];

  // variables para pruebas de size
  // int test01 = size(NameAge); // 2
  int test = size(NameAge[0]); // 6

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
    }
  }

  // imprimir el arreglo bidimensional con estructuras
  cout << "Los nombres y edades de los estudiantes de la clase son: " << endl;
  for (int j = 0; j < size(NameAge); j++) {
    for (int i = 0; i < size(NameAge[0]); i++) {
      cout << NameAge[j][i].name << " - ";
      cout << NameAge[j][i].age << endl;
    }
  }

  return 0;
}