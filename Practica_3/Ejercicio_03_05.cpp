// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int promedio(float nota, int peso);
int main(){
    int cont = 0;
    int suma = 0;
    srand(time(0));
    for(int i = 1; i <= 4; i++){
        cont += 10;
        int nota = rand() % (100 + 1);
        cout << "Nota del examen " << i << ": " << nota << endl;
        cout << "Peso del examen " << i << ": " << cont << "%" << endl;
        cout << "Promedio ponderado: " << promedio(nota, cont) << endl;
        cout << "-----------------------------" << endl;
        suma += promedio(nota, cont);
    }
    cout << "El promedio final ponderado es: " << suma << endl;

    return 0;
}
int promedio(float nota, int peso){
    return nota / 100 * peso;
}