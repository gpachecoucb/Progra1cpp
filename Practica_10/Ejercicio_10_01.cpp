// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void EscribirArchivoTexto(string NombreArchivo);
void LeerArchivoTexto(string NombreArchivo);
int main(){
    string NombreArchivo = "Lista_Nombre.txt";
    EscribirArchivoTexto(NombreArchivo);
    LeerArchivoTexto(NombreArchivo);
    return 0;
}
void EscribirArchivoTexto(string NombreArchivo){
    ofstream archivo;
    archivo.open(NombreArchivo);
    if(archivo.good()){
        string nombre;
        do{
            cout << "Escriba un nombre (cuando termine, escriba salir): ";
            cin >> nombre;
            archivo << nombre;
            archivo << endl;
        }while(nombre != "salir");
        cout << "Se guardaron los nombres correctamente" << endl;
    }
    archivo.close();
}
void LeerArchivoTexto(string NombreArchivo){
    ifstream archivo_leer;
    archivo_leer.open("Lista_Nombre.txt");
    if(archivo_leer.good()){
        string linea;
        while(!archivo_leer.eof()){
            getline(archivo_leer, linea);
            cout << linea << endl;
        }
    }
    archivo_leer.close();
}