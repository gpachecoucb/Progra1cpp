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
    int m;
    cout << "Ingrese el orden de la matriz cuadrada: ";
    cin >> n;
    cout << "Ingrese el número de columnas: ";
    cin >> m;
    int matriz[n][m];
    int matriz2[m][n];
    srand(time(0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matriz[i][j] = rand() % 10;

        }
    }
    cout << "Matriz generada: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            matriz2[i][j] = rand() % 10;   
        }   
    }
    cout << "Matriz para la multiplicación: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Matriz resultante de la multiplicación: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int suma = 0;
            for(int k=0; k<m; k++){
                suma += matriz[i][k] * matriz2[k][j];
            }
            cout << suma << "\t";
        }
        cout << endl;
    }
    
    return 0;
}