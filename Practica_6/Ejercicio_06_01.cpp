// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 1
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
    vector<int> numeros;
    int numero = 0;
    int contador = 0;
    float sumador = 0;
    float promedio = 0;
    float varianza = 0;
    float desviacion_estandar = 0;
    cout << "Ingrese números enteros (ingrese -1 para terminar):" << endl;
    do{
        cin >> numero;
        if(numero != -1){
            numeros.push_back(numero);
            contador++;
            sumador += numero;
        }
    }while (numero != -1);
    float sumador_diferencia_con_promedio = 0;
    promedio = sumador / contador;
    for(int i = 0; i < numeros.size(); i++){
        int diferencia_con_promedio = 0;
        diferencia_con_promedio = numeros[i] - promedio;
        sumador_diferencia_con_promedio += diferencia_con_promedio^2;
    }
    varianza = sumador_diferencia_con_promedio / contador;
    desviacion_estandar = sqrt(varianza);
    cout << "Promedio: " << promedio << endl;
    cout << "Varianza: " << varianza << endl;
    cout << "Desviación estándar: " << desviacion_estandar << endl;

    return 0;
    
    
    
}