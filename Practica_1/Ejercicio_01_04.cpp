#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 4
int main() {
    int radio_esfera = 0;
    cout << "Ingrese el radio de la esfera" << endl;
    cin >> radio_esfera;
    cout << "El volumen de la esfera es: " << (4.0/3.0) * 3.1416 * (radio_esfera * radio_esfera * radio_esfera) << endl;
    return 0;
    
}