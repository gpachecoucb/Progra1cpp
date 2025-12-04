// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ContadorPalabrasArchivoTexto(string NombreArchivo);
int main(){
    string NombreArchivo = "texto.txt";
    cout << "La cantidad de palabras es: " << ContadorPalabrasArchivoTexto(NombreArchivo);
    return 0;
}

int ContadorPalabrasArchivoTexto(string NombreArchivo){
    ifstream archivo_leer;
    archivo_leer.open(NombreArchivo);
    int contador_palabras;
    if(archivo_leer.good()){
        string linea;
        while(!archivo_leer.eof()){
            getline(archivo_leer, linea);
            for(int i = 0; i<linea.size(); i++){
                if(linea[i] == ' '){
                    contador_palabras++;
                }
                if(i+1 == linea.size() && linea[i] != ' '){
                    contador_palabras++;
                }
            }
        }
    }
    archivo_leer.close();
    return contador_palabras;
}