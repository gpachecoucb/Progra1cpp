// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 8
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LeerArchivoTexto(string NombreArchivo);
void PromedioCalificaciones(string ArchivoEntrada);
int main(){
    string NombreArchivo = "documento.txt";
    LeerArchivoTexto(NombreArchivo);
    PromedioCalificaciones(NombreArchivo);
    return 0;
}

void ContarDocumento(string NombreArchivo){
    fstream archivo;
    archivo.open(NombreArchivo, ios::in);

    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;

    bool dentroPalabra = false;
    char c;

    while (archivo.get(c)) {   // Leer carácter por carácter
        caracteres++;

        // Contar líneas
        if (c == '\n') {
            lineas++;
        }

        // Detectar palabras
        if (c != ' ' && c != '\n' && c != '\t') {
            // Estamos dentro de una palabra
            if (!dentroPalabra) {
                palabras++;
                dentroPalabra = true;
            }
        } else {
            // Llegamos a un separador → finaliza palabra
            dentroPalabra = false;
        }
    }

    // Si el archivo no termina con salto de línea, hay al menos una línea
    if (caracteres > 0) {
        lineas++;
    }

    archivo.close();

    // ---- Mostrar resultados ----
    cout << "Lineas: " << lineas << endl;
    cout << "Palabras: " << palabras << endl;
    cout << "Caracteres: " << caracteres << endl;
}

