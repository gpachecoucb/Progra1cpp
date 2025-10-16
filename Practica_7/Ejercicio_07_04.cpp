// Materia: Programación I, Paralelo 3
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 15/10/2024
// Número de ejercicio: 2
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int main(){
    int n;
    int elemento = 1;
    cout << "Ingrese el orden de la matriz cuadrada: ";
    cin >> n;
    int matriz[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j] = elemento+j;
            
            
        }
        elemento += 2;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}