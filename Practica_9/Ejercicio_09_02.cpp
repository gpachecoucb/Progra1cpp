// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco.
// Fecha creación: 06/11/2025
// Número de ejercicio: 1
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
struct Atleta
{
    char nombre[50];
    char pais[50];
    int edad;
    int mejor_tiempo; 

};
Atleta AgregarAtleta();
void mostrarAtleta(Atleta atleta1);
Atleta AtletaMejorTiempo(vector<Atleta> atletas);
int main()
{
    vector<Atleta> atletas;
    int n;
    cout<<"Ingrese el número de atletas: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del atleta "<<i+1<<":"<<endl;
        Atleta atleta = AgregarAtleta();
        atletas.push_back(atleta);
    }
    Atleta mejorAtleta = AtletaMejorTiempo(atletas);
    cout<<"El atleta con el mejor tiempo es:"<<endl;
    mostrarAtleta(mejorAtleta);
    return 0;
}
Atleta AtletaMejorTiempo(vector<Atleta> atletas){
    Atleta mejorAtleta = atletas[0];
    for(size_t i = 1; i < atletas.size(); i++){
        if(atletas[i].mejor_tiempo < mejorAtleta.mejor_tiempo){
            mejorAtleta = atletas[i];
        }
    }
    return mejorAtleta;
}

Atleta AgregarAtleta(){
    struct Atleta atleta1;
    cout<<"Ingrese el nombre del atleta: ";
    cin.getline(atleta1.nombre,50);
    cout<<"Ingrese el pais de la atleta: ";
    cin.getline(atleta1.pais,50);
    cout<<"Ingrese la edad del atleta: ";  
    cin>>atleta1.edad;
    cout<<"Ingrese el mejor tiempo del atleta (en segundos): ";
    cin>>atleta1.mejor_tiempo;
    cin.ignore();
    return atleta1;
    
}
void mostrarAtleta(Atleta atleta1){
    cout<<"Nombre: "<<atleta1.nombre<<endl;
    cout<<"Pais: "<<atleta1.pais<<endl;
    cout<<"edad: "<<atleta1.edad<<endl;
    cout<<"Mejor tiempo (en segundos): "<<atleta1.mejor_tiempo<<endl;
    
}