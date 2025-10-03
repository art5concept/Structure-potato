// Este programa ilustra el uso de punteros para crear una matriz
// dinamica en C++ con compatibilidad hacia C.

// librerias necesarias
#include <iostream>

using namespace std;

int main() {

  // pedir al usuario filas y columnas para la matriz
  cout << "Cuantas filas tiene la matriz" << endl;
  int filas;
  cin >> filas;
  cout << "Cuantas columnas tiene la matriz" << endl;
  int columnas;
  cin >> columnas;

  // ====== incorrecto uso de punteros para matriz dinamica ======
  // primero se debe reservar memoria para filas y columnas
  //   int *matriz;

  //   matriz = &columnas; // error
  // matriz = &filas;      // error
  // ============

  // declarar un puntero a puntero para la matriz dinamica
  int **matriz;

  // error de punteros no inicializados *no repetir*
  // inicializar el puntero a puntero en nullptr
  *matriz = nullptr;

  // derivar filas y columnas a punteros
  *matriz = &filas;
  *matriz = &columnas;

  //   ==== Codigo error====
  //   matriz = (int *)malloc(filas * columnas * sizeof(int));

  //   if (matriz == NULL) {
  //     cout << "ERROR: Regreso un puntero NULL";
  //   } else {
  //     cout << "Puntero alocado en el heap correctamente";
  //   }

  // se podria usar solo como arreglo unidimensional
  // [columnas] no es valido

  //   matriz[filas][columnas];
  //   =====================

  // En C++ no se puede almacenar memoria dinamica para una matriz bidimensional
  // usando solo 1 malloc cuando se usa malloc para reservar memoria para una
  // matriz bidimensional, se debe reservar memoria para un arreglo de punteros
  // que apunten a enteros

  // reservar memoria para la matriz dinamica con malloc
  matriz = (int **)malloc(filas * sizeof(int *));

  // reservar memoria para cada fila de la matriz
  for (int i = 0; i < filas; i++) {
    // *(matriz + i) = (int *)malloc(columnas * sizeof(int));
    matriz[i] = (int *)malloc(columnas * sizeof(int));
  }

  // pedir al usuario los datos para la matriz
  for (int j = 0; j < filas; j++) {
    for (int i = 0; i < columnas; i++) {
      cout << "Inserte el valor para la posicion [" << j << "][" << i << "]: ";
      cin >> matriz[j][i];
    }
  }

  // imprimir la matriz
  cout << "========== La matriz ingresada es =========" << endl;
  for (int j = 0; j < filas; j++) {
    for (int i = 0; i < columnas; i++) {
      cout << "El valor para la posicion [" << j << "][" << i
           << "]: " << matriz[j][i];
      cout << endl;
    }
  }

  // liberar la memoria de la matriz

  for (int i = 0; i < filas; i++) {

    // liberar cada fila de punteros a enteros
    // free(matriz[i]);
    free(*(matriz + i));
  }

  // liberar el arreglo de punteros a punteros
  free(matriz);

  return 0;
}

// ================== salida de valgrind =========================

// ➜  proyectoEjemplo git:(main) ✗ g++ -g lab25.cpp -o lab25
// ➜  proyectoEjemplo git:(main) ✗ valgrind --leak-check=full ./lab25
// ==24655== Memcheck, a memory error detector
// ==24655== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==24655== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==24655== Command: ./lab25
// ==24655==
// Cuantas filas tiene la matriz
// 2
// Cuantas columnas tiene la matriz
// 3
// ==24655== Use of uninitialised value of size 8
// ==24655==    at 0x1092AB: main (lab25.cpp:32)
// ==24655==
// ==24655== Use of uninitialised value of size 8
// ==24655==    at 0x1092BA: main (lab25.cpp:35)
// ==24655==
// ==24655== Use of uninitialised value of size 8
// ==24655==    at 0x1092C5: main (lab25.cpp:36)
// ==24655==
// Inserte el valor para la posicion [0][0]: 1
// Inserte el valor para la posicion [0][1]: 2
// Inserte el valor para la posicion [0][2]: 3
// Inserte el valor para la posicion [1][0]: 4
// Inserte el valor para la posicion [1][1]: 5
// Inserte el valor para la posicion [1][2]: 6
// ========== La matriz ingresada es =========
// El valor para la posicion [0][0]: 1
// El valor para la posicion [0][1]: 2
// El valor para la posicion [0][2]: 3
// El valor para la posicion [1][0]: 4
// El valor para la posicion [1][1]: 5
// El valor para la posicion [1][2]: 6
// ==24655==
// ==24655== HEAP SUMMARY:
// ==24655==     in use at exit: 0 bytes in 0 blocks
// ==24655==   total heap usage: 6 allocs, 6 frees, 75,816 bytes allocated
// ==24655==
// ==24655== All heap blocks were freed -- no leaks are possible
// ==24655==
// ==24655== Use --track-origins=yes to see where uninitialised values come from
// ==24655== For lists of detected and suppressed errors, rerun with: -s
// ==24655== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

// =====================================================
// los errores de lineas 23, 25 y 26 son por el uso incorrecto de punteros para
// almacenar filas y columnas, no afectan la ejecucion del programa pero si
// generan errores en tiempo de ejecucion al usar valgrind para corregirlos se
// debe eliminar las lineas 23, 25 y 26 o usar malloc primero para reservar
// memoria para filas y columnas

// =====================================================