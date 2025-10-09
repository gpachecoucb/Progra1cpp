// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 8  
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    string correo;
    cout << "ingrese el correo electrónico" << endl;
    getline(cin, correo);
    cout << correo << endl;
    int arroba = 0;
    int punto = 0;
    for(int i = 0; i < correo.size(); i++){
        if(correo[i] == '@'){
            arroba += 1;
        }
        if(correo[i] == '.' && arroba == 1){
            punto+=1;
        }
        
    }
    if(arroba+punto >= 2 && arroba == 1){
        cout<<"CORREO VALIDO"<< endl;
    }
    else{
        cout<<"CORREO INVALIDO" << endl;
    }
    return 0;
}