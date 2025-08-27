#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 8
int main() {
    int numero = 0;
    cout << "Ingrese un número entero" << endl;
    cin >> numero;
    if(numero % 2 == 0){
        cout << "El número es par" << endl;
    }
    else{
        cout << "El número es impar" << endl;
    }
}