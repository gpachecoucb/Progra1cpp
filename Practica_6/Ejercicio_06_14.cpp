// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 14
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int vocal_a = 0;
    int vocal_e = 0;
    int vocal_i = 0;

    int vocal_o = 0;
    int vocal_u = 0;
    string frase;
    cout << "ingrese una frase" << endl;
    getline(cin, frase);
    for(int i = 0; i < frase.size(); i++){
        if(frase[i] == 'a' || frase[i] == 'A'){
            vocal_a++;
        }
        else if(frase[i] == 'e' || frase[i] == 'E'){
            vocal_e++;
        }
        else if(frase[i] == 'i' || frase[i] == 'I'){
            vocal_i++;
        }
        else if(frase[i] == 'o' || frase[i] == 'O'){
            vocal_o++;
        }
        else if(frase[i] == 'u' || frase[i] == 'U'){
            vocal_u++;
        }
    }
    cout << "Cantidad de vocales:" << endl;
    cout << "a: " << vocal_a << endl;
    cout << "e: " << vocal_e << endl;
    cout << "i: " << vocal_i << endl;
    cout << "o: " << vocal_o << endl;
    cout << "u: " << vocal_u << endl;
    return 0;
    


}