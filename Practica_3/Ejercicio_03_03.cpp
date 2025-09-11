// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int numero_capicua(int numero);
int main(){
    int numero;
    cout << "Ingrese un número entero: ";
    cin >> numero;
    if(numero_capicua(numero) == 1){
        cout << "El número " << numero << " es capicúa." << endl;   
    }
    else{
        cout << "El número " << numero << " no es capicúa." << endl;   
    }
    return 0;
}
int numero_capicua(int numero){
    int original = numero;
    int invertido = 0;
    while(numero != 0){
        int digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
    }
    if(original == invertido){
        return 1; // Capicúa
    }else{
        return 0; // No es capicúa
    }
}