// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 7
#include <iostream>
using namespace std;
int main(){
    int numero1, numero2;
    int mcm = 0;
    int mcd = 0;
    int con = 0;
    int mayor = 0;
    cout << "Ingrese dos números enteros: ";
    cin >> numero1 >> numero2;
    while(mcm == 0){
        con++;
        if(con % numero1 == 0 && con % numero2 == 0){
            mcm = con;
        }

    }
    if(numero1 > numero2){
        mayor = numero1;
    }
    else{
        mayor = numero2;
    }
    for(int i = 1; i <= mayor; i++){
        if(numero1 % i == 0 && numero2 % i == 0){
            mcd = i;
            
        }
    }
    cout << "El MCM es: " << mcm << endl;
    cout << "El MCD es: " << mcd << endl;

    return 0;
}