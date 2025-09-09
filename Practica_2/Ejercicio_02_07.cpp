// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int inicio = 1;
    int fin = 3;
    int numero_aleatorio;
    int N;
    int edad1 = 0;
    int edad2 = 0;
    int edad3 = 0;
    srand(time(0));
    cout << "cuantos numeros aleatorios: ";
    cin >> N;
    for(int i = 0; i < N; i++){
        numero_aleatorio = (rand() % (fin - inicio + 1)) + 1;
        if(numero_aleatorio == 1){
            edad1 ++;
        }
        else if(numero_aleatorio == 2){
            edad2 ++;
        }
        else if(numero_aleatorio == 3){
            edad3 ++;
        }

    }
    cout << edad1 << " niños de 1 año" << endl;
    cout << edad2 << " niños de 2 año" << endl;
    cout << edad3 << " niños de 3 año" << endl;
    cout << "cantidad de pañales utilizado = " << edad1 * 6 + edad2 * 3 + edad3 * 2;

    return 0;
}