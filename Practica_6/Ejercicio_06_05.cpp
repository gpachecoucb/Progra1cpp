// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 5
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    vector <string> nombres_empresa_1 = {"Gabriel", "Ana", "Luis", "Maria", "Carlos", "Sofia", "Jorge", "Lucia", "Pedro", "Elena"};
    vector <string> nombres_empresa_2 = {"Gabriel", "Marian", "Lourdes", "Laura", "Charlie", "Leonardo", "Maria", "Amilkar", "Pedro", "Nino"};
    for(int i = 0; i < nombres_empresa_1.size(); i++){
        for(int j = 0; j < nombres_empresa_2.size(); j++){
            if(nombres_empresa_1[i] == nombres_empresa_2[j]){
                cout << "Empleado en ambas empresas: " << nombres_empresa_1[i] << endl;
            }
        }
    }
}