// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco.
// Fecha creación: 06/11/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct pelicula 
{
    char titulo[50];
    char director[50];
    int duracion;
    int anio_estreno;
    char genero[50];

};
pelicula Agregarpelicula();
void mostrarpelicula(pelicula pelicula1);
void mostrarPeliculasGenero(vector<pelicula> peliculas, string genero);
void mostrarPeliculasDirector(vector<pelicula> peliculas, string director);


int main()
{
    vector<pelicula> peliculas;
    int n;
    string directorBuscado;
    string generoBuscado;
    cout<<"Ingrese el número de peliculas: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del pelicula "<<i+1<<":"<<endl;
        pelicula pelicula = Agregarpelicula();
        peliculas.push_back(pelicula);
    }
    
    cout<<"Ingrese el genero de las peliculas que desea buscar: ";
    getline(cin, generoBuscado);
    cout<<"Peliculas del genero "<<generoBuscado<<":"<<endl;
    mostrarPeliculasGenero(peliculas, generoBuscado);
    
    cout<<"Ingrese el director de las peliculas que desea buscar: ";
    getline(cin, directorBuscado);
    cout<<"Peliculas del director "<<directorBuscado<<":"<<endl;
    mostrarPeliculasDirector(peliculas, directorBuscado);
    
    return 0;
}
pelicula Agregarpelicula(){
    struct pelicula pelicula1;
    cout <<"Ingrese el titulo del pelicula: ";
    cin.getline(pelicula1.titulo,50);
    cout<<"Ingrese el director del pelicula: ";
    cin.getline(pelicula1.director,50);
    cout<<"Ingrese la duracion del pelicula (en minutos): ";
    cin>>pelicula1.duracion;
    cout<<"Ingrese el año de estreno del pelicula: ";
    cin>>pelicula1.anio_estreno;
    cin.ignore();
    cout<<"Ingrese el genero del pelicula: ";
    cin.getline(pelicula1.genero,50);
    
    

    return pelicula1;
    
}
void mostrarpelicula(pelicula pelicula1){
    cout<<"Título: "<<pelicula1.titulo<<endl;
    cout<<"Director: "<<pelicula1.director<<endl;
    cout<<"Duración (en minutos): "<<pelicula1.duracion<<endl;
    cout<<"Año de estreno: "<<pelicula1.anio_estreno<<endl;
    cout<<"Género: "<<pelicula1.genero<<endl;

    
}
void mostrarPeliculasGenero(vector<pelicula> peliculas, string genero){
    for(size_t i = 0; i < peliculas.size(); i++){
        if(peliculas[i].genero == genero){
            mostrarpelicula(peliculas[i]);
        }
        
    }
}
void mostrarPeliculasDirector(vector<pelicula> peliculas, string director){
    for(size_t i = 0; i < peliculas.size(); i++){
        if(peliculas[i].director == director){
            mostrarpelicula(peliculas[i]);
        }
        
    }
}