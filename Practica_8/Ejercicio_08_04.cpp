// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 1
#include <iostream>

#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;



int mcd(int a, int b) {
    if (b == 0)
        return a;  
    else
        return mcd(b, a % b);  
}

int main() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << "El MCD de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;
    return 0;
}
