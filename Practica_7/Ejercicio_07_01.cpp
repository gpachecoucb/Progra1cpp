
// Materia: Programación I, Paralelo 3
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 15/10/2024
// Número de ejercicio: 2
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    int n;
    int fila;
    cout << "Ingrese el orden de la matriz cuadrada (maximo 10): ";

    cin >> n;
    int numero[n][n];

    srand(time(0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            numero[i][j] = rand() % 100;
        }
    }
    cout << "Matriz generada: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << numero[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Elija la fila con la que quiera intercambiar la fila 1:";
    cin >> fila;
    fila = fila - 1;
    for(int j=0; j<n; j++){
        int temp = numero[0][j];
        numero[0][j] = numero[fila][j];
        numero[fila][j] = temp;
    }
    cout << "Matriz resultante: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << numero[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;

    

}