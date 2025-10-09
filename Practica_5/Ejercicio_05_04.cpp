// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 4
// Problema planteado:
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    int n;
    int n1;
    cout<<"Ingrese la cantidad de números a ingresar: ";
    cin>>n;
    vector<int> numeros;
    for(int i=0; i<n; i++){
        int num;
        cout<<"Ingrese el número "<<i+1<<": ";
        cin>>num;
        numeros.push_back(num);
    }
    cout<<"Ingrese la cantidad de numeros para el segundo vector: ";
    cin>>n1;
    vector<int> numeros2;
    for(int i=0; i<n1; i++){
        int num;
        cout<<"Ingrese el número "<<i+1<<": ";
        cin>>num;
        numeros2.push_back(num);
    }
    cout<<"Números del primer vector:"<<endl;
    for(int i=0; i<numeros.size(); i++){
        cout<<"Número "<<i+1<<": "<<numeros[i]<<endl;
    }
    cout<<"Números del segundo vector:"<<endl;
    for(int i=0; i<numeros2.size(); i++){
        cout<<"Número "<<i+1<<": "<<numeros2[i]<<endl;
    }
    return 0;
    vector<int> multiplicacion;
    for(int i=0; i<min(numeros.size(), numeros2.size()); i++){
        multiplicacion.push_back(numeros[i]*numeros2[i]);
    }
    cout<<"Números del vector multiplicación:"<<endl;
    for(int i=0; i<multiplicacion.size(); i++){
        cout<<"Número "<<i+1<<": "<<multiplicacion[i]<<endl;
    }
    return 0;
}