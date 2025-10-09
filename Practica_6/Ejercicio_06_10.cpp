// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 10
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    string oracion;
    cout << "ingrese una oracion" << endl;
    getline(cin, oracion);
    string nueva_oracion;
    for(int i = 0; i < oracion.size(); i++){
        if(oracion[i] >= 48 && oracion[i] <= 57){
            oracion.erase(i, 1);
            i--;
        }
       
        
    }
    cout << oracion << endl;
    
    
    return 0;
    
}