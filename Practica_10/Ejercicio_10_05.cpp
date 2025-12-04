// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 04/11/2025
// Número de ejercicio: 5
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void EscribirArchivoTexto(string NombreArchivo);
void LeerArchivoTexto(string NombreArchivo);
void EscribirTemperaturaArchivoTexto(string NombreArchivo);
int main(){
    string NombreArchivo = "productos.txt";
    EscribirArchivoTexto(NombreArchivo);
    cout << "Escriba el nombre del prodcuto quiere cambiar su precio"<<endl;
    LeerArchivoTexto(NombreArchivo);
    return 0;
}
void EscribirArchivoTexto(string NombreArchivo){
    ofstream archivo;
    archivo.open(NombreArchivo);
    if(archivo.good()){
        string nombre;
        double precio;
        do{
            cout << "Escriba el nombre del producto (cuando termine, escriba salir): ";
            cin >> nombre;
            if(nombre != "salir"){
                archivo << nombre << " ";
                cout << "Escriba su precio: ";
                cin >> precio;
                archivo << precio << endl;

            }
        }while(nombre != "salir");
        cout << "Se guardaron los estudiantes correctamente" << endl;
    }
    archivo.close();
}
void CambiarPrecioArchivoTexto(string NombreArchivo, string NombreProducto){
    fstream archivo_leer;
    archivo_leer.open(NombreArchivo, ios::in);

    if (!archivo_leer.good()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    vector<string> lineas;
    string linea;
    bool encontrado = false;

    // Leer archivo línea por línea
    while (getline(archivo_leer, linea)) {
        
        bool sw = true;

        // Verificar si el inicio de la línea coincide con el nombre
        for (int i = 0; i < NombreProducto.size(); i++) {
            if (i >= linea.size() || NombreProducto[i] != linea[i]) {
                sw = false;
                break;
            }
        }

        if (sw) {
            encontrado = true;
            int NuevoPrecio;
            cout << "Ingrese el nuevo precio para " << NombreProducto << ": ";
            cin >> NuevoPrecio;

            // Crear nueva línea: Producto + espacio + precio
            string nuevaLinea = NombreProducto + " " + to_string(NuevoPrecio);

            lineas.push_back(nuevaLinea);
        }
        else {
            // Guardar la línea tal cual
            lineas.push_back(linea);
        }
    }

    archivo_leer.close();

    if (!encontrado) {
        cout << "El producto no existe en el archivo." << endl;
        return;
    }

    // Reabrir archivo en modo escritura, vaciándolo
    fstream archivo_escribir;
    archivo_escribir.open(NombreArchivo, ios::out | ios::trunc);

    for (int i = 0; i < lineas.size(); i++) {
        archivo_escribir << lineas[i] << endl;
    }

    archivo_escribir.close();

    cout << "Precio actualizado exitosamente." << endl;
}