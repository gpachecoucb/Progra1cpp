// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 7
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int funcion_recursiva_secuencia(int n);
int main()
{
    int n;
    cout << "Ingrese un número entero positivo: ";
    cin >> n;
    if (n < 0) {
        cout << "Por favor, ingrese un número entero positivo." << endl;
    } else {
        cout << "Resultado de la función recursiva para " << n << " es: ";
        cout << funcion_recursiva_secuencia(n);
        cout << endl;
    }
    return 0;
}
int funcion_recursiva_secuencia(int n){
    if(n == 0){
        return 0;
    } else {
        return (n*n) + (funcion_recursiva_secuencia(n - 1));
    }
}