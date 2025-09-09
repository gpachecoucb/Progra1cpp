// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 1

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    int numero, aleatorio;
    srand(time(0));
    aleatorio = 1 + rand() % (6 - 1 + 1);
    cout << "Lanzamiento de un dado: " << endl;
    cout << aleatorio << endl;
    
    
    return 0;
}

