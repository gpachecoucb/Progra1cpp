// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 03/09/2025
// Número de ejercicio: 22
#include <iostream>
using namespace std;
int main()
{
    int n;
    int m;
    cout << "Ingrese dos numeros enteros: " << endl;
    cin >> n;  
    cin >> m;
    if(n > m){
        if(n % m == 0){
            cout << n << " es multiplo de " << m << endl;
        }
        else{
            cout << n << " no es multiplo de " << m << endl;
        }
    }
    else if(m >n){
        if(m % n == 0){
            cout << m << " es multiplo de " << n << endl;
        }
        else{
            cout << m << " no es multiplo de " << n << endl;
        }
    }
    else{
        cout << m << " es multiplo de " << n << endl;
    }

    return 0;
}