#include <iostream>
#include <iterator>

using namespace std;

int main() {

  float productos[5] = {};
  int i = 0;
  float total = 0, producto = 0;

  while (i < size(productos)) {
    cout << "Ingrese costo del producto = ";
    cin >> productos[i];
    producto = productos[i];

    // Ciclo para validar que el precio sea mayor a 0
    while (producto <= 0) {
      cout << "++++++++++" << endl;
      printf("Introduce el precio correcto, el precio que introdujiste es "
             "invalido = %.2f\n",
             producto);
      cout << "Ingrese costo del producto = ";
      cin >> productos[i];
      producto = productos[i];
    }
    i++;
  }

  i = 0;

  printf("++++++++++++++++++\n");

  //   Ciclo para sumar los precios
  do {
    total += productos[i];
    i++;
  } while (i < size(productos));

  //   Operaciones para el total, descuento e ITBMS
  printf("El total sin el descuento es de = %.2f\n", total);
  printf("El total con el descuento del 40%% es de = %.2f\n",
         total * (1 - 0.4));
  printf("El total a pagar con el ITBMS es de = %.2f\n", total * 1.07 * 0.6);

  return 0;
}