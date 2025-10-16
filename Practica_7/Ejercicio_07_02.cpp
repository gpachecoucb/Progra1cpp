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
    int producto_ultima_fila = 1;
    int suma_ultima_col = 0;
    int n;
    int mayor = 0;
    
    double desviacion = 0.0;
    double media = 0.0;
    double suma = 0.0;
    int fila;
    int columna;
    cout << "Ingrese el orden de la matriz cuadrada (maximo 10): ";

    cin >> n;
    int numero[n][n];
    int desviaciones[n][n];


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
    cout << "Suma de la ultima columna: ";
    for(int i=0; i<n; i++){
        suma_ultima_col += numero[i][n-1];
    }
    cout << suma_ultima_col << endl;
    cout << "Producto de la ultima fila: ";
    for(int j=0; j<n; j++){
        producto_ultima_fila *= numero[n-1][j];
    }
    cout << producto_ultima_fila << endl;
    cout << "El mayor valor de la matriz: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(numero[i][j] > mayor){
                mayor = numero[i][j];
                fila = i + 1;
                columna = j + 1;
            }
        }
    }
    cout << mayor << " es el mayor y se encuentra en la fila " << fila << " columa "<< columna  << endl;
    cout << "desviacion estandar de elementos de la matriz: [en su respectiva posicion]" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            suma += numero[i][j];
        }
    }
    media = suma / (n*n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            desviacion = sqrt(pow((numero[i][j] - media), 2) / (n*n));
            desviaciones[i][j] = desviacion;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << desviaciones[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;

}