// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 7
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LeerArchivoTexto(string NombreArchivo);
char cifrarCesar(char c);
int main(){
    string NombreArchivo = "mensaje.txt";
    LeerArchivoTexto(NombreArchivo);
    CifrarArchivoCesar(NombreArchivo);
    return 0;
}

char cifrarCesar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return ( (c - 'A' + 3) % 26 ) + 'A';
    }
    if (c >= 'a' && c <= 'z') {
        return ( (c - 'a' + 3) % 26 ) + 'a';
    }
    return c;
}

void CifrarArchivoCesar(string NombreArchivo){
    fstream archivo;
    archivo.open(NombreArchivo, ios::in);

    if (!archivo.good()) {
        cout << "No se pudo abrir mensaje.txt" << endl;
        return;
    }

    fstream salida;
    salida.open("mensaje_cifrado.txt", ios::out | ios::trunc);

    char c;

    while (archivo.get(c)) {
        char cifrado = cifrarCesar(c);
        salida << cifrado;
    }

    archivo.close();
    salida.close();

    cout << "Archivo mensaje_cifrado.txt generado correctamente." << endl;
}