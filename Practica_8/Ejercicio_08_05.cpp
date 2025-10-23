// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 5

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


int suma_vector(vector<int> a) {
    if(a .size() == 0) {
        return 0;
    } else {
        int ultimo = a.back();
        a.pop_back();
        return ultimo + suma_vector(a);
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int resultado = suma_vector(vec);
    cout << "La suma de los elementos del vector es: " << resultado << endl;
    return 0;
}
