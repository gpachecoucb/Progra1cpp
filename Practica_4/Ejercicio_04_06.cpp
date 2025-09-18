// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;

int main(){
    int numero1, digito;
    int sumador = 0;
    int contador = 0;
    cout << "Ingrese un número entero: ";
    cin >> numero1;
    
    while(numero1 > 0){
        digito = numero1 % 10;
        numero1 /= 10;
        sumador += digito;
        
    }
    cout << "La suma de los dígitos es: " << sumador << endl;
    for(int i = 2; i <= sumador/2; i++){
        
        if (sumador % i == 0){
            contador++;
            cout << contador << endl;
        }

    }
    if (contador == 0){
        cout << "El número es primo." << endl;
    } else {
        cout << "El número no es primo." << endl;
    }
}