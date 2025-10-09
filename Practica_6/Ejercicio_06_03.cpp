// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 3
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    int N = 0;
    vector <string> nombres = {"Gabriel", "Ana", "Luis", "Maria", "Carlos", "Sofia", "Jorge", "Lucia", "Pedro", "Elena"};
    vector <string> apellidos = {"Pacheco", "Lopez", "Garcia", "Martinez", "Rodriguez", "Hernandez", "Gonzalez", "Perez", "Sanchez", "Ramirez"};
    vector <int> edades = {22, 19, 25, 21, 23, 20, 24, 18, 26, 22};
    srand(time(0));
    int indice_aleatorio = 0;
    int indice_aleatorio2 = 0;
    int indice_aleatorio3 = 0;
    cout << "Ingrese la cantidad: " << endl;
    cin >> N;
    for(int i = 0; i < N; i++){
        indice_aleatorio = rand() % nombres.size();
        indice_aleatorio2 = rand() % apellidos.size();
        indice_aleatorio3 = rand() % edades.size();
        cout << nombres[indice_aleatorio] << " " << apellidos[indice_aleatorio2] << ", " << edades[indice_aleatorio3] << " años" << endl;
    } 
    return 0;
}