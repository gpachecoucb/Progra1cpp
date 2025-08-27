#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 12
int main() {
    int numero = 0; 
    
    do
    {
        cout << "Ingrese un número entero entre 1 al 5" << endl;            
        cin >> numero;
          
    } while (numero < 1 || numero > 5);
    cout << "El número ingresado es: " << numero << endl;
    return 0;
}