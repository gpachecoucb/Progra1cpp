// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 6
// Problema planteado:
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    vector<int> v1(10);
    int n;

    do{
        cout<<"Ingrese números enteros positivos: "<<endl;
        cin>>n;
        if(n>0){
            v1.push_back(n);
        }
        else{
            cout<<"Número inválido, intente de nuevo."<<endl;
        }
    }while (n>=0 && v1.size()<10);
    cout<<"Números ingresados: "<<endl;
    for(int i=0; i<v1.size(); i++){
        cout<<"Número "<<i+1<<": "<<v1[i]<<endl;
    }
    
    
    return 0;
}