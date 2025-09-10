#include <iostream>

// Libreria para usar size()
// Se puede usar tambien sizeof() pero es mas complicado

// Si no se coloca esta libreria puede que el compilador
// la agregue automaticamente pero no es seguro
#include <iterator>

using namespace std;

int main() {

  float grades[15] = {};

  int i = 0;
  float grade = 0;

  // Curiosisdad del retorno de numero de caracteres
  // si se escribe cout y printf seguido retorna la cadena y el numero de
  // caracteres cout << printf("abc")<<endl; cout << printf("introduce las
  // notas")<<endl;

  while (i < size(grades)) {
    cout << "Ingrese nota = ";
    cin >> grades[i];
    grade = grades[i];

    // Ciclo para validar que la nota este entre 0 y 100
    while (grade >= 100 || grade <= 0) {
      cout << "++++++++++" << endl;
      printf("Introduce la nota nuevamente en un rango de 0 a 100 la nota "
             "error fue = %.2f\n",
             grade);
      cout << "Ingrese nota = ";
      cin >> grades[i];
      grade = grades[i];
    }

    i++;
  }

  i = 0;

  printf("++++++Notas finales de los estudiantes++++++\n");
  while (i < size(grades)) {
    printf("Nota = %.2f\n", grades[i]);

    i++;
  }

  return 0;
}