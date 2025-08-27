// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 23
#include <iostream>
using namespace std;
int main()
{
    int numero;
    int nue_numero = 0;
    cout << "Ingrese un numero" << endl;
    cin >> numero;
    while(numero > 0){
        int residuo = numero % 10;
        nue_numero += residuo;
        nue_numero *=10;
        numero = numero / 10;
        
    }
    
    cout << "El numero invertido es " << nue_numero / 10 << endl;
    
    return 0;
}