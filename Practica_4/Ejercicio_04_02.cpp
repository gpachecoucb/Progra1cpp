// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;
double CalcularVolumen(double radio, double altura);
int main(){
    double radio = 3.0, altura = 5.0;
    cout << "El volumen del cilindro es: " << CalcularVolumen(radio, altura) << endl;
    return 0;
}
double CalcularVolumen(double radio, double altura = 10){
    const double PI = 3.1416;
    return PI * radio * radio * altura;
}