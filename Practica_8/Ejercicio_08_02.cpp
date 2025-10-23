// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 2
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int potencia(int b, int e);
int main()
{
    int n;
    int e;
    cout << "ingrese un número: " << endl;
    cin >> n;
    cout << "ingrese el exponente: " << endl;
    cin >> e;
    cout << n << " elevado a " << e << " es igual a: "<< potencia(n, e);
}
int potencia(int b, int e){

    if(e > 0){
        return b*potencia(b, e-1);
    }
    else{
        return 1;
    }
}

    