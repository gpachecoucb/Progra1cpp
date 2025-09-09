// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 24512548 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
    int aleatorio, n;
    int factorial = 1;
    srand(time(0));
    aleatorio = 1 + rand() % (10+1);
    cout << "Numero del uno al diez: " << aleatorio << endl;
    for (int i = 1; i <= aleatorio; i++) {
        
        factorial = factorial * i;
    }
    cout << "El factorial de " << aleatorio << " es: " << factorial << endl;
    
    
    
    return 0;
}