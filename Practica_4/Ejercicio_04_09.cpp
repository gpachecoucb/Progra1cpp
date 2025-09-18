// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 9
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int n;
    int ventas_vendedora = 0;
    int precio_producto = 0;
    cout << "Ingrese el número de vendedorass contratadas: ";
    cin >> n;
    cout << "Ingrese el precio del producto: ";
    cin >> precio_producto;
    for(int i = 1; i <= n; i++){
        ventas_vendedora = 1 + rand() % (20 - 1 + 1);
        cout << "Vendedora " << i << ": " << ventas_vendedora << " productos vendidos." << endl;
        cout << "Total a pagar a la vendedora " << i << ": " << ventas_vendedora * precio_producto * 0.1 + ventas_vendedora * precio_producto  << endl;
        
    }
}