// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 5
// Problema planteado:
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    vector<int> v1 = {5,2,3,4,5};
    vector<int> v2 = {2,3,1,5,4};
    vector<int> combinacion;
    for(int i=0; i<v1.size()+v2.size(); i++){
        if(i >= v1.size()){
            combinacion.push_back(v2[i-v1.size()]);
        }
        else{
            combinacion.push_back(v1[i]);
        }
    }
    return 0;
}