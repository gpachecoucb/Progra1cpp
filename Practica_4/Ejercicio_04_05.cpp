// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;
int main(){
    int horast, salario, bonificacion;
    cout << "Ingrese el número de horas trabajadas en el dia: ";
    cin >> horast;
    cout << "Ingrese el salario por hora: ";
    cin >> salario;
    cout << "Ingrese la bonificación fija mensual: (En porcetaje 0-100) ";
    cin >> bonificacion;
    if(horast <= 8){
        cout << "El salario total del trabajador es: " << (horast * salario) << " Bolivianos" << endl;
    } else {
        int horas_extra = horast - 8;
        double pago_horas_extra = horas_extra * salario * bonificacion/100.0;
        cout << "El salario total del trabajador es: " << (horast * salario) + pago_horas_extra<< " Bolivianos" << endl;
    }
    return 0;
}