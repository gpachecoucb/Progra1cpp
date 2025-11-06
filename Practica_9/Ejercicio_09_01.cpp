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
struct libro
{
    char titulo[50];
    char autor[50];
    int anio_publicacion;
    bool disponible;
};
libro Agregarlibro(){
    struct libro libro1;
    cout<<"Ingrese el titulo del libro: ";
    cin.getline(libro1.titulo,50);
    cout<<"Ingrese el autor del libro: ";
    cin.getline(libro1.autor,50);
    cout<<"Ingrese el año de publicación del libro: ";
    cin>>libro1.anio_publicacion;
    cout<<"¿El libro está disponible? (1 para sí, 0 para no): ";
    cin>>libro1.disponible;
    return libro1;
    
}
void mostrarLibro(libro libro1){
    cout<<"Título: "<<libro1.titulo<<endl;
    cout<<"Autor: "<<libro1.autor<<endl;
    cout<<"Año de publicación: "<<libro1.anio_publicacion<<endl;
    cout<<"Disponible: ";
    if(libro1.disponible){
        cout<<"Sí"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
int main()
{
    libro miLibro = Agregarlibro();
    mostrarLibro(miLibro);
    return 0;
}