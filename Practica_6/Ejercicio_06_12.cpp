// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 12
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
bool esPalindromo(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}
int main(){
    string palabra;
    cout << "ingrese una palabra" << endl;
    getline(cin, palabra);
    if(esPalindromo(palabra)){
        cout << "La palabra es un palíndromo" << endl;
    }
    else{
        cout << "La palabra no es un palíndromo" << endl;
    }
    return 0;
}