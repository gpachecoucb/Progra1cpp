// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 2
// Problema planteado:

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    vector<double> voltajes= {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};
    for(int i=0; i<voltajes.size(); i++){
        cout<<"Voltaje "<<i+1<<": "<<voltajes[i]<<endl;
    }
    return 0;
}