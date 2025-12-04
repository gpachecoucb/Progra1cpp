// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int BuscarPalabra(string NombreArchivo, string Palabra_Buscar);
int main(){
    string NombreArchivo = "datos.txt";
    string Palabra_Buscar;
    getline(cin, Palabra_Buscar);
    BuscarPalabra(NombreArchivo, Palabra_Buscar);
    return 0;
}

int BuscarPalabra(string NombreArchivo, string Palabra_Buscar){
    int contador;
    ifstream archivo_leer;
    archivo_leer.open(NombreArchivo);
    if(archivo_leer.good()){
        string linea;
        while(!archivo_leer.eof()){
            getline(archivo_leer, linea);
            for(int i = 0; i<linea.size(); i++){
                if(linea[i] == Palabra_Buscar[0]){
                    bool sw;
                    for(int j; i<Palabra_Buscar.size(); j++){
                        if(linea[i+j] != Palabra_Buscar[j]){
                            sw == false;
                        }
                    }
                    if(sw == true){
                        contador++;
                    }
                }
                
            }
            
        }
    }
    archivo_leer.close();
    return contador;
}