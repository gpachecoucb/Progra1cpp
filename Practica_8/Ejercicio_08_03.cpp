// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 3
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
#include <iostream>

int fibonacci_recursivo(int n) {
    
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2){
        return 1;
        }
    if (n == 3){
        return 1;
    }
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int main() {
    int numero;

    cout << "Introduce un número entero para calcular el enésimo término de Fibonacci: ";
    cin >> numero;
    if (numero < 0) {
        cout << "La entrada debe ser un número no negativo." << endl;
    } else {
        int resultado = fibonacci_recursivo(numero);
        cout << "El enésimo número de Fibonacci es: " << resultado << endl;
    }

    return 0;
}
    