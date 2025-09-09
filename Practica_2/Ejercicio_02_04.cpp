// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 4
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int inicio = 1;
    int fin = 50;
    int numero_aleatorio;
    int numero;
    srand(time(0));
    numero_aleatorio = (rand() % (fin - inicio + 1)) + 1;
    do{
        cout << "Adivina el numero que esta entre " << inicio << " y " << fin << endl;
        cin >> numero;
        if(numero >= inicio  && numero < numero_aleatorio){
            inicio = numero; 
        }
        else if(numero <= fin && numero > numero_aleatorio){
            fin = numero;
        }
        else if(numero == numero_aleatorio)
        {
            cout << "Encontraste el numero!!! " << numero_aleatorio;
        }
        else{
            cout << "Escoja un valor valido" << endl;
        }
    }while(numero != numero_aleatorio);
    
    return 0;
    
}