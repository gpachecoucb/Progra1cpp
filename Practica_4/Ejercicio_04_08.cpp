// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 8
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    srand(time(0));
    int n;
    int venta = 0;
    int total_ventas = 0;
    cout << "Ingrese el nunmero de ventas: "<< endl;
    cin >> n;
    
    for(int i = 1; i<= n; i++){
        venta = 20 + rand() % (50 - 20 + 1);
        cout << "Venta " << i << ": " << venta << endl;
        total_ventas += venta;
    }
    cout << "El total de ventas es: " << total_ventas << endl;
    if(total_ventas <= 2500){
        cout << "La ganancia total con IVA es:" << total_ventas + total_ventas*10/100 << endl;

    }
    else{
        cout << "La ganancia total con IVA es:" << total_ventas + total_ventas*0.13 - total_ventas*0.05 << endl;    
    }
    cout << "IVA = " << total_ventas*0.13  << endl;

    return 0;
}