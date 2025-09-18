// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 17/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
void MayorTemperatura(double temp1, double temp2);
double ConvertirCelsiusAFahrenheit(double celsius);
int main(){
    double tempC;
    double tempC1, tempC2;
    cout << "Ingrese la temperatura en grados Celsius: ";
    cin >> tempC;

    ConvertirCelsiusAFahrenheit(tempC);
    cout << "La temperatura en grados Fahrenheit es: " << ConvertirCelsiusAFahrenheit(tempC) << " °F" << endl;
    cout << "Ingrese la primera temperatura en grados Celsius: ";
    cin >> tempC1;
    cout << "Ingrese la segunda temperatura en grados Celsius: ";
    cin >> tempC2;
    MayorTemperatura(tempC1, tempC2);
    return 0;
}
double ConvertirCelsiusAFahrenheit(double celsius){
    return (celsius * 9.0 / 5.0) + 32.0;
}
void MayorTemperatura(double temp1, double temp2){
    if(temp1 > temp2){
        cout << "La mayor temperatura es: " << temp1 << " °C" << endl;
    } else if(temp2 > temp1){
        cout << "La mayor temperatura es: " << temp2 << " °C" << endl;
    } else {
        cout << "Ambas temperaturas son iguales: " << temp1 << " °C" << endl;
    }
}