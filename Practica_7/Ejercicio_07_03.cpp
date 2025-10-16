// Materia: Programación I, Paralelo 3
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 15/10/2024
// Número de ejercicio: 2
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
void mostrar_zonas(char zonas_carcel[3][4]); //a)
void mostrar_fila_columnas_seguras(char zonas_carcel[3][4]); //b)
void coordenadas_zonas_muertos(char zonas_carcel[3][4], vector<int> &indice_filas_muertos, vector<int> &indice_columnas_muertos); //c)
int cantidad_muertos(char zonas_carcel[3][4]); //d)
bool posibilidad_entrar(char zonas_carcel[3][4]); //e)

int main(){
    char zonas_carcel[3][4] = {{'x','o','x','o'},{'o','o','o','o'},{'o','o','x','o'}};
    vector<int> indice_filas_muertos;
    vector<int> indice_columnas_muertos;
    cout << "a)" << endl;
    mostrar_zonas(zonas_carcel);
    cout << "b)" << endl;
    mostrar_fila_columnas_seguras(zonas_carcel);
    cout << "c)" << endl;
    coordenadas_zonas_muertos(zonas_carcel, indice_filas_muertos, indice_columnas_muertos);
    cout << "Coordenadas de las zonas con muertos vivientes: " << endl;
    for(size_t i=0; i<indice_filas_muertos.size(); i++){
        cout << "(" << indice_filas_muertos[i]<< ", " << indice_columnas_muertos[i] << ")" << endl;
    }
    cout << "d)" << endl;
    cout << "Cantidad de zonas con muertos vivientes: " << cantidad_muertos(zonas_carcel) << endl;
    cout << "e)" << endl;
    if(posibilidad_entrar(zonas_carcel)){
        cout << "Es posible entrar a la carcel." << endl;
    } else {
        cout << "No es posible entrar a la carcel." << endl;
    }
    return 0;
}
void mostrar_zonas(char zonas_carcel[3][4]){
    cout << "Zonas de la carcel (x = zona con muerto viviento, o = zona segura): " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << zonas_carcel[i][j] << "\t";
        }
        cout << endl;
    }
}
void mostrar_fila_columnas_seguras(char zonas_carcel[3][4]){
    int filas_seguras = 0;
    int columnas_seguras = 0;
    for(int i=0; i<3; i++){
        bool fila_segura = true;
        for(int j=0; j<4; j++){
            if(zonas_carcel[i][j] == 'x'){
                fila_segura = false;
                
            }
        }
        if(fila_segura){
            filas_seguras++;
            cout << "Fila " << i+1 << " es segura." << endl;
        }
    }
    for(int j=0; j<4; j++){
        bool columna_segura = true;
        for(int i=0; i<3; i++){
            if(zonas_carcel[i][j] == 'x'){
                columna_segura = false;
                
            }
        }
        if(columna_segura){
            columnas_seguras++;
            
        }
    }
    cout << "Filas seguras: " << filas_seguras << endl;
    cout << "Columnas seguras: " << columnas_seguras<<endl;

}
void coordenadas_zonas_muertos(char zonas_carcel[3][4], vector<int> &indice_filas_muertos, vector<int> &indice_columnas_muertos){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(zonas_carcel[i][j] == 'x'){
                indice_filas_muertos.push_back(i);
                indice_columnas_muertos.push_back(j);
            }
        }
    }
}
int cantidad_muertos(char zonas_carcel[3][4]){
    int contador = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(zonas_carcel[i][j] == 'x'){
                contador++;
            }
        }
    }
    return contador;
} 
bool posibilidad_entrar(char zonas_carcel[3][4]){
    int contador = 0;
    for(int i=0; i<3; i++){
        
        if(zonas_carcel[i][0] == 'x'){
            
            contador++;
        }
        
        
    }
    if(contador >= 2){
        return false;
    }
    else{
        return true;
    }
    
}

