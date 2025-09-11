// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 10
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double calcular_tarifa(double kmrecorridos);
int main(){
    double kmrecorridos;
    cout << "Ingrese los kilómetros recorridos: ";
    cin >> kmrecorridos;
    cout << "La tarifa a pagar es: " << calcular_tarifa(kmrecorridos) << endl;
    return 0;
}
double calcular_tarifa(double kmrecorridos){
    if(kmrecorridos < 1){
        return 10.00;

    }
    else if(kmrecorridos >= 1 && kmrecorridos < 10){
        return 10.00 + (kmrecorridos*2.00);
    }
    else if(kmrecorridos >= 10){
        return 10.00 + (kmrecorridos*2.50) - (kmrecorridos*2.50)*0.10;
    }
    
    
    else{
        return -1; 
    }
}