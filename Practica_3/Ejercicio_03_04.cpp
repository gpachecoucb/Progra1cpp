// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
int IMC(float peso, float altura);
int main(){
    int peso;
    float altura;
    cout << "Ingrese su peso en kilogramos: ";
    cin >> peso;
    cout << "Ingrese su altura en metros: ";
    cin >> altura;
    cout << "Su Índice de Masa Corporal (IMC) es: " << IMC(peso, altura) << endl;

    return 0;
}
int IMC(float peso, float altura){
    float imc = peso / (altura * altura);
    
    return imc;
}