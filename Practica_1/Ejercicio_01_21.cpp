// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 21
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Ingrese los 2 numeros a multiplicar" << endl;
    cin >>a >> b;
    int res = 0;
    for(int i = 0; i < b; i++){
        res += a;
    }
    cout << "El resultados es: " << res;
    return 0;
}