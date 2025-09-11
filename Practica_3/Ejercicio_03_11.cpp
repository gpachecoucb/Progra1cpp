// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 11
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double retirarDinero(double saldo, int cantidad);
int main(){
    double saldo;
    int cantidad;
    cout << "Ingrese su saldo actual: ";
    cin >> saldo;
    cout << "Ingrese la cantidad a retirar: ";
    cin >> cantidad;
    int resultado = retirarDinero(saldo, cantidad);
    if(resultado == 0){
        cout << "No puede retirar dinero, su saldo es menor o igual a 1000." << endl;
        return 0;
    }
    else if(resultado == 1){
        cout << "La cantidad a retirar debe ser un múltiplo de 10." << endl;
        return 0;
    }
    else if(resultado == 2){
        cout << "No puede retirar más dinero del que tiene en su cuenta." << endl;
        return 0;
    }
    else{
        saldo = resultado;
        cout << "Retiro exitoso de: " << cantidad << endl;
    }
    cout << "Su saldo actual es: " << saldo << endl;

    return 0;
}
double retirarDinero(double saldo, int cantidad){
    if(saldo < 1000){
        return 0;
    }
    else{
        if(cantidad % 10 == 0){
            if(cantidad <= saldo){
                return saldo - cantidad;
            }
            else{
                return 2; 
            }
        }
        else{
            return 1;
        }
    }

}