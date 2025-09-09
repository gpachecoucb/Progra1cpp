// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int suma = 0;
    int max = 0;
    int min = 1001;
    int inicio = 1;
    int fin = 1000;
    int numero_aleatorio;
    int numero;
    cout << "Numero de veces para genera numeros del 1 al 1000" << endl;
    cin >> numero;
    srand(time(0));
    for(int i = 0; i < numero; i++){
        numero_aleatorio = (rand() % (fin - inicio + 1)) + 1;
        cout << numero_aleatorio;
        suma += numero_aleatorio;
        if(max < numero_aleatorio){
            max = numero_aleatorio;
        }
        if(min > numero_aleatorio){
            min = numero_aleatorio;
        }
    }
    cout << " EL PROMEDIO ES: " << suma / numero << endl;
    cout << " SUMATORIA: " << suma << endl;
    cout << " VALOR MAXIMO: " << max << endl;
    cout << " VALOR MINIMO: " << min << endl; 
    

    return 0;
}