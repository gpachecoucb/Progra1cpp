// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 6
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int dias_mes (int mes);
int main(){
    int mes;
    cout << "Ingrese un número de mes (1-12): ";
    cin >> mes;
    int dias = dias_mes(mes);
    if(dias != -1){
        cout << "El mes " << mes << " tiene " << dias << " días." << endl;
    }else{
        cout << "Número de mes inválido. Por favor ingrese un número entre 1 y 12." << endl;
    }
    return 0;
}
int dias_mes (int mes){
    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 29; 
        default:
            return -1; 
    }
}