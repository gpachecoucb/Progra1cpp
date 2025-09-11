// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;
int conversor_farenheit(int celsius);

int main(){
    int celsius;
    cout << "Ingrese la temperatura en grados Celsius: ";
    cin >> celsius;
    cout << celsius << " grados Celsius son " << conversor_farenheit(celsius) << " grados Farenheit." << endl;
    
    return 0;
}
int conversor_farenheit(int celsius){
    return (celsius * 9/5) + 32;
}
