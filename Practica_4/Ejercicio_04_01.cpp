// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 1

#include <iostream>
using namespace std;
void Intercambiar(int &n1, int &n2);
int main(){
    int numero1 = 1, numero2 = 4;
    cout << "El valor de numero1 es: " << numero1 << endl;
    cout << "El valor de numero2 es: " << numero2 << endl;
    Intercambiar(numero1, numero2);
    cout << "El valor de numero1 es: " << numero1 << endl;
    cout << "El valor de numero2 es: " << numero2 << endl;
    return 0;
}
void Intercambiar(int &n1, int &n2){
    int aux;
    aux = n1;
    n1 = n2;
    n2 = aux;
}
