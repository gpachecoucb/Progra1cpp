// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 4
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    vector <int> numeros;
    vector <int> numeros_rotados;
    int N = 0;
    cout << "Ingrese la cantidad de números: " << endl;
    cin >> N;
    for(int i = 0; i < N; i++){
        int numero_aleatorio = rand() % 100 + 1;
        numeros.push_back(numero_aleatorio);
    }
    cout << "Números generados: " << endl;
    for(int i = 0; i < numeros.size(); i++){
        cout << numeros[i] << " ";
    }
    cout << endl;
    int k = 0;
    cout << "Ingrese el valor de k (número de posiciones a rotar): ";
    cin >> k;
    k = k % N; 
    for(int i = 0; i < N; i++){
        
        int nueva_posicion = (i - k) % N;
        if(nueva_posicion < 0){
            nueva_posicion += N; 
        }
        numeros_rotados.push_back(numeros[nueva_posicion]);
    }
    cout << "Números rotados: " << endl;
    for(int i = 0; i < numeros_rotados.size(); i++){
        cout << numeros_rotados[i] << " ";
    }
    return 0;
}