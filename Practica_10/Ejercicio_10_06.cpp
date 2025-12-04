// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 6
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void EscribirArchivoTexto(string NombreArchivo);
void LeerArchivoTexto(string NombreArchivo);
void FiltrarAltasTemperaturas(string ArchivoEntrada, int N);
int main(){
    string NombreArchivo = "temperaturas.txt";
    EscribirArchivoTexto(NombreArchivo);
    cout << "Escriba el nombre del prodcuto quiere cambiar su precio"<<endl;
    LeerArchivoTexto(NombreArchivo);
    cout << "Ingrese la cantidad alta de temperatura" << endl;
    int N;
    cin >> N;
    void FiltrarAltasTemperaturas(string ArchivoEntrada, int N);
    return 0;
}
void EscribirArchivoTexto(string NombreArchivo){
    ofstream archivo;
    archivo.open(NombreArchivo);
    if(archivo.good()){
        string nombre;
        double temperatura;
        do{
            cout << "Escriba el nombre del pais (cuando termine, escriba salir): ";
            cin >> nombre;
            if(nombre != "salir"){
                archivo << nombre << " ";
                cout << "Escriba su temperatura: ";
                cin >> temperatura;
                archivo << temperatura << endl;

            }
        }while(nombre != "salir");
        cout << "Se guardaron los estudiantes correctamente" << endl;
    }
    archivo.close();
}
void FiltrarAltasTemperaturas(string ArchivoEntrada, int N){
    fstream archivo;
    archivo.open(ArchivoEntrada, ios::in);

    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo de temperaturas." << endl;
        return;
    }

    vector<string> altas;
    string linea;

    while (getline(archivo, linea)) {

        string ciudad = "";
        string tempStr = "";
        int i = 0;

        while (i < linea.size() && linea[i] != ' ') {
            ciudad += linea[i];
            i++;
        }
        i++;


        while (i < linea.size()) {
            tempStr += linea[i];
            i++;
        }
        int temperatura = stoi(tempStr);
        if (temperatura > N) {
            altas.push_back(ciudad + " " + to_string(temperatura));
        }
    }
    archivo.close();
    fstream salida;
    salida.open("altas_temperaturas.txt", ios::out | ios::trunc);
    for (int i = 0; i < altas.size(); i++) {
        salida << altas[i] << endl;
    }
    salida.close();
    cout << "Archivo altas_temperaturas.txt generado correctamente." << endl;
}
