// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 11
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    string frase = "Esto,es,una,cadena,separada,por,comas";
    vector <string> palabras;
    for(int i = 0; i < frase.size(); i++){
        string palabra;
        while(frase[i] != ',' && i < frase.size()){
            palabra += frase[i];
            i++;
        }
        palabras.push_back(palabra);
    }
    for(int i = 0; i < palabras.size(); i++){
        cout << palabras[i] << endl;
    }
    return 0;

}