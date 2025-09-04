
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 03/09/2025
// Número de ejercicio: 19
#include <iostream>
using namespace std;
int main()
{
    
    int n;
    cout << "Ingrese el numero del que quiere su tabla " << endl;
    cin >> n;
    cout << "TABLA DEL " << n << endl;
    for(int i = 1; i <= 10; i++){
        int res = n*i;
        cout << n << " x " << i << " = " << res << endl;
    }
    
    return 0;
}