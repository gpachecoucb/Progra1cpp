// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 1
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int suma_digitos(int d);
int main()
{
    int n;
    cout << "ingrese un número: " << endl;
    cin >> n;
    cout << "La suma de los dígitos es: "<< suma_digitos(n);
}
int suma_digitos(int d){

    if(d > 0){
        return d%10 + suma_digitos(d/10);
    }
    else{
        return 0;
    }
}

    