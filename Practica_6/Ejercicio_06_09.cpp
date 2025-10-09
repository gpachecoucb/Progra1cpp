// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 9
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
    string palabra;
    for(int i = 0; i<oracion.size(); i++){
        palabra+= oracion[i];
        if(oracion[i] == ' ' || i == oracion.size()-1){
            if(oracion.size() -1 == i){
                nueva_oracion.insert(0," ");
                nueva_oracion.insert(0,palabra);
            }
            else{
                nueva_oracion.insert(0,palabra);
            }
            
            palabra.erase(0,palabra.size());
            
        }
    }
    cout << "nueva oración: " << nueva_oracion<< endl;
    
    
    return 0;
    
}