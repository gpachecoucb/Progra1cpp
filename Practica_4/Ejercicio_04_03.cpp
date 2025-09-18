// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int ModificarValor(int a, int &b);
int main(){
    int numero1, numero2;
    cout << "Ingrese un valor para numero1: ";
    cin >> numero1;
    cout << "Ingrese un valor para numero2: ";
    cin >> numero2;
    cout << "El valor de numero1 es: " << numero1 << endl;
    cout << "El valor de numero2 es: " << numero2 << endl;
    int resultado = ModificarValor(numero1, numero2);
    cout << "El valor de numero1 es: " << numero1 << endl;
    cout << "El valor de numero2 es: " << numero2 << endl;
    cout << "El resultado es: " << resultado << endl;
    return 0;
}
int ModificarValor(int a, int &b){
    b += 10; ;
    return a*2;
}