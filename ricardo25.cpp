// Este programa ilustra el uso de punteros para crear una matriz
// dinamica en C++ realizado de forma mas moderna.

#include <iostream>
using namespace std;

int main() {
  cout << "\n--- Problema 5: Arreglo Dinamico con Entrada de Usuario ---"
       << endl;

  int filas, columnas;

  cout << "Introduce el numero de filas para el arreglo: ";
  cin >> filas;
  cout << "Introduce el numero de columnas para el arreglo: ";
  cin >> columnas;

  if (filas <= 0 || columnas <= 0) {
    cout << "? Error: filas y columnas deben ser mayores que 0." << endl;
    return 1;
  }

  //   int **matriz = new int *[filas];
  int **matriz = new int *[filas];
  for (int i = 0; i < filas; ++i) {
    matriz[i] = new int[columnas];
  }

  // simplifico la entrada de datos
  // (no se pide al usuario que ingrese los datos)

  //   cout << "\nIntroduce los datos (enteros) para rellenar la matriz:" <<
  //   endl; for (int i = 0; i < filas; ++i) {
  //     for (int j = 0; j < columnas; ++j) {
  //       cout << "Dato para matriz[" << i << "][" << j << "]: ";
  //       cin >> matriz[i][j];
  //     }
  //   }

  // inicializo la matriz con unos para simplificar
  matriz[0][0] = 1;
  matriz[0][1] = 1;
  matriz[1][0] = 1;
  matriz[1][1] = 1;

  cout << "\n--- Arreglo Dinamico Final ---" << endl;
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      cout << matriz[i][j] << "\t";
    }
    cout << endl;
  }

  // libero la memoria
  // uso delete[] para liberar memoria asignada con new[]
  // primero libero cada fila y luego el arreglo de punteros
  for (int i = 0; i < filas; ++i) {
    delete[] matriz[i];
  }
  delete[] matriz;

  // evito dangling pointer
  matriz = NULL;

  return 0;
}

// ================== salida de valgrind =========================
// ➜  proyectoEjemplo git:(main) ✗ g++ -g ricardo25.cpp -o ricardo25
// ➜  proyectoEjemplo git:(main) ✗ valgrind --leak-check=full ./ricardo25
// ==23539== Memcheck, a memory error detector
// ==23539== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==23539== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==23539== Command: ./ricardo25
// ==23539==

// --- Problema 5: Arreglo Dinamico con Entrada de Usuario ---
// Introduce el numero de filas para el arreglo: 2
// Introduce el numero de columnas para el arreglo: 3

// --- Arreglo Dinamico Final ---
// ==23539== Conditional jump or move depends on uninitialised value(s)
// ==23539==    at 0x49B3A7D: std::ostreambuf_iterator<char,
// std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char,
// std::char_traits<char> >
// >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char>
// >, std::ios_base&, char, long) const (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49C43C1: std::ostream& std::ostream::_M_insert<long>(long)
// (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x10946E: main (ricardo25.cpp:49)
// ==23539==
// ==23539== Use of uninitialised value of size 8
// ==23539==    at 0x49B395B: ??? (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49B3AA7: std::ostreambuf_iterator<char,
// std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char,
// std::char_traits<char> >
// >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char>
// >, std::ios_base&, char, long) const (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49C43C1: std::ostream& std::ostream::_M_insert<long>(long)
// (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x10946E: main (ricardo25.cpp:49)
// ==23539==
// ==23539== Conditional jump or move depends on uninitialised value(s)
// ==23539==    at 0x49B396D: ??? (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49B3AA7: std::ostreambuf_iterator<char,
// std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char,
// std::char_traits<char> >
// >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char>
// >, std::ios_base&, char, long) const (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49C43C1: std::ostream& std::ostream::_M_insert<long>(long)
// (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x10946E: main (ricardo25.cpp:49)
// ==23539==
// ==23539== Conditional jump or move depends on uninitialised value(s)
// ==23539==    at 0x49B3ADC: std::ostreambuf_iterator<char,
// std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char,
// std::char_traits<char> >
// >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char>
// >, std::ios_base&, char, long) const (in
// /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x49C43C1: std::ostream& std::ostream::_M_insert<long>(long)
// (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==23539==    by 0x10946E: main (ricardo25.cpp:49)
// ==23539==
// 1       1       0
// 1       1       0
// ==23539==
// ==23539== HEAP SUMMARY:
// ==23539==     in use at exit: 0 bytes in 0 blocks
// ==23539==   total heap usage: 6 allocs, 6 frees, 75,816 bytes allocated
// ==23539==
// ==23539== All heap blocks were freed -- no leaks are possible
// ==23539==
// ==23539== Use --track-origins=yes to see where uninitialised values come from
// ==23539== For lists of detected and suppressed errors, rerun with: -s
// ==23539== ERROR SUMMARY: 8 errors from 4 contexts (suppressed: 0 from 0)