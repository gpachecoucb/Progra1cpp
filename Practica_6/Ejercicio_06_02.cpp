// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 2
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
    
    vector <string> nombres_minerales = {"SN", "SB", "AU", "PT", "AG", "CU"};
    vector <float> produccion_minerales = {135.567, 786.670, 998.000, 636.143, 876.500, 109.412};
    vector <float> minerales_ordenados;
    vector <string> nombres_ordenados;
    float mayor = 0;
    int puntero = 0;
    while(produccion_minerales.size() > 0){
        int mayor = 0;
        int indice_mayor = 0;
        for(int j = 0; j < produccion_minerales.size(); j++){
            if(mayor < produccion_minerales[j]){
                mayor = produccion_minerales[j];
                indice_mayor = j;
            }
        }
        
        cout << endl;
        minerales_ordenados.push_back(mayor);
        nombres_ordenados.push_back(nombres_minerales[indice_mayor]);
        produccion_minerales.erase(produccion_minerales.begin() + indice_mayor);
        nombres_minerales.erase(nombres_minerales.begin() + indice_mayor);
    }
    

        
        
    
    for(int i = 0; i < minerales_ordenados.size(); i++){
        cout << nombres_ordenados[i] << ": " << minerales_ordenados[i] << " toneladas" << endl;
    }
    return 0;
}