// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 20
#include <iostream>
using namespace std;
int main()
{
    int numero;
    int digitos = 0;
    cout << "Ingrese un numero" << endl;
    cin >> numero;
    while(numero > 0){
        digitos ++;
        numero = numero / 10;
    }
    cout << "La cantidad de digitos del numero es: " << digitos << endl;
    
    return 0;
}