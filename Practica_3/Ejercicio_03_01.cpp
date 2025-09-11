// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
int par_o_impar(int numero){
    if(numero % 2 == 0){
        return 1; // Par
    }else{
        return 0; // Impar
    }
}
int main(){

    int numero;
    cout << "Ingrese un número entero: ";
    cin >> numero;
    if(par_o_impar(numero) == 1){
        cout << "El número " << numero << " es par." << endl;   
    }
    else{
        cout << "El número " << numero << " es impar." << endl;   
    }

    return 0;
}