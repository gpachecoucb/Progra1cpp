// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 13
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    string frase;
    cout << "ingrese una frase" << endl;
    getline(cin, frase);
    for(int i = 0; i < frase.size(); i++){
        if(i == 0){
             if(frase[i] >= 'a' && frase[i] <= 'z'){
                frase[i] = frase[i] - 32;
            }
        }
        else if((frase[i-1] == ' ')){
            if(frase[i] >= 'a' && frase[i] <= 'z'){
                frase[i] = frase[i] - 32;
            }
        }
    }
    cout << frase << endl;

    return 0;
}