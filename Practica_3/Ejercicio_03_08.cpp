// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 8
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int billete_desgloce(int monto);
int main(){
    int monto;
    cout << "Ingrese el monto a desglosar: ";
    cin >> monto;
    billete_desgloce(monto);
    return 0;
}
int billete_desgloce(int monto){
    int billetes_200 ,billetes_100, billetes_50, billetes_20, billetes_10, monedas_5, monedas_2, monedas_1;
    billetes_200 = monto / 200;
    monto = monto % 200;
    billetes_100 = monto / 100;
    monto = monto % 100;
    billetes_50 = monto / 50;
    monto = monto % 50;
    billetes_20 = monto / 20;
    monto = monto % 20;
    billetes_10 = monto / 10;
    monto = monto % 10;
    monedas_5 = monto / 5;
    monto = monto % 5;
    monedas_2 = monto / 2;
    monto = monto % 2;
    monedas_1 = monto / 1;
    cout << "Desglose de billetes:" << endl;
    if(billetes_200 > 0){
        cout << "Billetes de 200: " << billetes_200 << endl;
    }
    if(billetes_100 > 0){
        cout << "Billetes de 100: " << billetes_100 << endl;
    }
    if(billetes_50 > 0){
        cout << "Billetes de 50: " << billetes_50 << endl;
    }
    if(billetes_20 > 0){
        cout << "Billetes de 20: " << billetes_20 << endl;
    }
    if(billetes_10 > 0){
        cout << "Billetes de 10: " << billetes_10 << endl;
    }
    if(monedas_5> 0){
        cout << "Billetes de 5: " << monedas_5 << endl;
    }
    if(monedas_2 > 0){
        cout << "Monedas de 2: " << monedas_2 << endl;
    }
    if(monedas_1 > 0){
        cout << "Monedas de 1: " << monedas_1 << endl;
    }

    return 0;
}
