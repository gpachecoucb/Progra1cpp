// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 3
// Problema planteado:
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    srand(time(0));
    int n;
    float promedio=0;
    float suma=0;
    float suma_descviacion=0;
    cout<<"Ingrese la cantidad calificaciones: ";
    cin>>n;
    vector<double> calificaciones;
    for(int i=0; i<n; i++){
        calificaciones.push_back(rand()%(101));
    }
    cout<<"Calificaciones generadas: "<<endl;
    for(int i=0; i<calificaciones.size(); i++){
        
        cout<<"Calificación "<<i+1<<": "<<calificaciones[i]<<endl;
        suma+=calificaciones[i];
    }
    promedio=suma/n;
    cout<<"El promedio de las calificaciones es: "<<promedio<<endl;
    for(int i=0; i<calificaciones.size(); i++){
        
        cout<<"Calificación "<<i+1<<": "<<calificaciones[i]<<" desviacion "<<calificaciones[i]-promedio<<endl;
        suma_descviacion+=pow(calificaciones[i]-promedio,2);

    }
    cout<<"La desviacion estandar es: "<<sqrt(suma_descviacion/n)<<endl;
    return 0;
}