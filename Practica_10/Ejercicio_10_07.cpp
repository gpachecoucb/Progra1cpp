// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 7
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void EscribirArchivoTexto(string NombreArchivo);
void LeerArchivoTexto(string NombreArchivo);
void PromedioCalificaciones(string ArchivoEntrada);
int main(){
    string NombreArchivo = "calificaciones.txt";
    EscribirArchivoTexto(NombreArchivo);
    cout << "Escriba el nombre del prodcuto quiere cambiar su precio"<<endl;
    LeerArchivoTexto(NombreArchivo);
    string NombreArchivoP = "promedios.txt";
    return 0;
}
void EscribirArchivoTexto(string NombreArchivo){
    ofstream archivo;
    archivo.open(NombreArchivo);
    if(archivo.good()){
        string nombre;
        float nota;
        do{
            cout << "Escriba el nombre del estudiante (cuando termine, escriba salir): ";
            cin >> nombre;
            if(nombre != "salir"){
                archivo << nombre << " ";
                cout << "Escriba su calificacion: ";
                cin >> nota;
                archivo << nota << " ";
                cout << "Escriba su calificacion: ";
                cin >> nota;
                archivo << nota << " ";
                cout << "Escriba su calificacion: ";
                cin >> nota;
                archivo << nota << endl;

            }
        }while(nombre != "salir");
        cout << "Se guardaron los estudiantes correctamente" << endl;
    }
    archivo.close();
}
void PromedioCalificaciones(string ArchivoEntrada){
    fstream archivo;
    archivo.open(ArchivoEntrada, ios::in);

    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo de calificaciones." << endl;
        return;
    }

    vector<string> promedios;
    string linea;

    while (getline(archivo, linea)) {

        string nombre = "";
        int i = 0;
        while (i < linea.size() && linea[i] != ' ') {
            nombre += linea[i];
            i++;
        }
        i++;
        int suma = 0;
        int contador = 0;
        string numero = "";
        while (i <= linea.size()) {

            if (i == linea.size() || linea[i] == ' ') {
                if (numero != "") {
                    suma += stoi(numero);
                    contador++;
                    numero = "";
                }
            }
            else {
                numero += linea[i];
            }
            i++;
        }
        double promedio = 0;
        if (contador > 0) {
            promedio = (double)suma / contador;
        }

        string resultado = nombre + " " + to_string(promedio);
        promedios.push_back(resultado);
    }
    archivo.close();
    fstream salida;
    salida.open("promedios.txt", ios::out | ios::trunc);
    for (int i = 0; i < promedios.size(); i++) {
        salida << promedios[i] << endl;
    }
    salida.close();
    cout << "Archivo promedios.txt generado correctamente." << endl;
}
