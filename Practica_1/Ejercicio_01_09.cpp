#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 9
int main() {
    int edad;
    cout << "Ingrese su edad" << endl;
    cin >> edad;
    if(edad <= 12){
        cout << "Es un niño" << endl;
    }
    else if(edad > 12 && edad <= 18){
        cout << "Es un adolescente" << endl;
    }
    else if(edad > 18 && edad < 60){
        cout << "Es mayor de edad" << endl;
    }
    else{
        cout << "Es un Adulto mayor" << endl;
    }
}