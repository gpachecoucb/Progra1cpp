#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 13
int main() {
    int numero;
    int sumador = 0;
    cout << "Ingrese un número natural" << endl;
    cin >> numero;

    if (numero > 0) {
        for (int i = 1; i <= numero; i++)
        {
            sumador += i;
        }
        cout << "La suma de los primeros " << numero << " números naturales es: " << sumador << endl;
    }
    else{
        cout << "Numero invalido" << endl;
    }
    return 0;
}