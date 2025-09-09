// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 09/09/2025
// Número de ejercicio: 6
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int N;
    int inicio = 1;
    int fin = 10000;
    int numero_aleatorio;
    int contador;
    int contador_primos = 0;
    srand(time(0));
    cout << "cuantos numeros aleatorios: ";
    cin >> N;
    for(int i = 0; i < N; i++){
        numero_aleatorio = (rand() % (fin - inicio + 1)) + 1;
        cout << numero_aleatorio << endl;
        contador = 0;
        for(int j = 2; j <= numero_aleatorio/2 + 1; j++)
        {
            if(numero_aleatorio % j == 0)
            {
                contador += 1;
            }
        }
        
        if(contador == 0)
        {
            contador_primos ++;
            cout << "es primo" << endl;
        }

        
    }
    cout << "HAY " << contador_primos << " numeros primos";
    return 0;
}