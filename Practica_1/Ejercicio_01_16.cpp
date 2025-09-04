// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 16
#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "Ingrese un numero entero  " << endl;
    cin >> N;
    int cont = 0;
    int suma = 2;
    while (cont == 0 && suma <= N/2) {
        
        if(N%suma == 0){
            cont++;
            cout << "El numero no es primo" << endl;
        }
        suma++;
    }
    cout << suma << endl;
    cout << N/2 << endl;
    if(suma == N/2+1){
        cout << "El numero es primo" << endl;
    }   
    return 0;
}