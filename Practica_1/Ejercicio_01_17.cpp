// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 17
#include <iostream>
using namespace std;
int main()
{
    int N;
    int M;
    cout << "Ingrese un numero entero  " << endl;
    cin >> N;
    cout << "Ingrese el segudo numero entero  " << endl;
    cin >> M;
    int suma1 = 0;
    int suma2 = 0;

    for (int i = 1; i <= N /2+1; i++)
    {
        if (N % i == 0 ){
            suma1 += i;
        }
    }
    for (int i = 1; i <= M /2+1; i++)
    {
        if (M % i == 0 ){
            suma2 += i;
        }
    }
    cout << suma1 << endl;
    cout << suma2 << endl;  
    if(suma1 == M && suma2 == N){
        cout << "Los numeros son amigos" << endl;
    }
    else{
        cout << "Los numeros no son amigos" << endl;
    }
    return 0;
}