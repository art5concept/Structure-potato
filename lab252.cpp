// Este programa ilustra el uso de vectores para crear una matriz
// dinamica en C++ usando for basado en rango.
// FORMA MODERNA Y RECOMENDADA EN C++ en 2025.
// =============================================================
// Probando ejemplo de matriz con for basado en rango
// regla simle de oro: modificar (cin, asignar valores) en un for tradicional
// solo leer recorrer todo y leer la matriz se usa for basado en rango
// para todo lo demas for tradicional

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int filas, columnas;
  cout << "Ingrese el número de filas: ";
  cin >> filas;
  cout << "Ingrese el número de columnas: ";
  cin >> columnas;

  vector<vector<int>> matriz(filas, vector<int>(columnas));

  cout << "Ingrese los elementos de la matriz:" << endl;

  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      cout << "Elemento [" << i << "][" << j << "]: ";
      cin >> matriz[i][j];
    }
  }
  // =====================Error rompiendo regla de oro ========================
  // Necesitas modificar (cin, asignar valores) en un for tradicional
  // Solo necesitas leer (cout) en un for basado en rango
  // ========================================================================
  //   for (const auto &fila : matriz) {
  //     for (const auto &elemento : fila) {
  //       cout << "Elemento [" << fila << "][" << elemento << "]: ";
  //       cin >> matriz[fila][elemento];
  //     }
  //   }
  // ========================================================================
  cout << "La matriz ingresada es:" << endl;
  for (const auto &fila : matriz) {
    for (const auto &elemento : fila) {
      cout << elemento << " ";
    }
    cout << endl;
  }
}
// ================= salida de valgrind =========================

// ➜  proyectoEjemplo git:(main) ✗ valgrind --leak-check=full ./lab252
// ==18414== Memcheck, a memory error detector
// ==18414== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==18414== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==18414== Command: ./lab252
// ==18414==
// Ingrese el número de filas: 2
// Ingrese el número de columnas: 3
// Ingrese los elementos de la matriz:
// Elemento [0][0]: 1
// Elemento [0][1]: 2
// Elemento [0][2]: 3
// Elemento [1][0]: 4
// Elemento [1][1]: 5
// Elemento [1][2]: 6
// La matriz ingresada es:
// 1 2 3
// 4 5 6
// ==18414==
// ==18414== HEAP SUMMARY:
// ==18414==     in use at exit: 0 bytes in 0 blocks
// ==18414==   total heap usage: 7 allocs, 7 frees, 75,860 bytes allocated
// ==18414==
// ==18414== All heap blocks were freed -- no leaks are possible
// ==18414==
// ==18414== For lists of detected and suppressed errors, rerun with: -s
// ==18414== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)