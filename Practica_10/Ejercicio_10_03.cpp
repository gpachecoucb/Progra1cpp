// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void EscribirArchivoTexto(string NombreArchivo);
void LeerArchivoTexto(string NombreArchivo);
int main(){
    string NombreArchivo = "productos.txt";
    EscribirArchivoTexto(NombreArchivo);
    LeerArchivoTexto(NombreArchivo);
    return 0;
}
void EscribirArchivoTexto(string NombreArchivo){
    ofstream archivo;
    archivo.open(NombreArchivo);
    if(archivo.good()){
        string nombre;
        int edad;
        float promedio; 
        do{
            cout << "Escriba un nombre (cuando termine, escriba salir): ";
            cin >> nombre;
            if(nombre != "salir"){
                archivo << "Nombre: " << nombre << endl;
                cout << "Escriba su edad: ";
                cin >> edad;
                archivo << "Edad: " << edad << endl;
                cout << "Escriba su promedio: " ;
                cin >> promedio ;
                archivo << "Promedio: " << promedio << endl << endl;
            }
        }while(nombre != "salir");
        cout << "Se guardaron los estudiantes correctamente" << endl;
    }
    archivo.close();
}
void LeerArchivoTexto(string NombreArchivo){
    ifstream archivo_leer;
    archivo_leer.open(NombreArchivo);
    if(archivo_leer.good()){
        string linea;
        while(!archivo_leer.eof()){
            getline(archivo_leer, linea);
            cout << linea << endl;
        }
    }
    archivo_leer.close();
}