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
struct Alumno
{
    int cedula;
    char nombre[50];
    char apellido[50];
    int edad;
    char profesion[50];
    char lugar_nacimiento[50];
    char direccion[100];
    int telefono; 

};
Alumno AgregarAlumno();
void mostrarAlumno(Alumno Alumno1);
Alumno AlumnoMejorTiempo(vector<Alumno> Alumnos);
int main()
{
    vector<Alumno> Alumnos;
    int n;
    cout<<"Ingrese el número de Alumnos: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del Alumno "<<i+1<<":"<<endl;
        Alumno Alumno = AgregarAlumno();
        Alumnos.push_back(Alumno);
    }
    for(int i = 0; i < n; i++){
        cout<<"Datos del Alumno "<<i+1<<":"<<endl;
        mostrarAlumno(Alumnos[i]);
    }
    
    return 0;
}


Alumno AgregarAlumno(){
    struct Alumno Alumno1;
    cout<<"Ingrese la cedula del Alumno: ";
    cin>>Alumno1.cedula;
    cout<<"Ingrese el nombre del Alumno: ";
    cin.getline(Alumno1.nombre,50);
    cout<<"Ingrese el apellido de la Alumno: ";
    cin.ignore();
    cin.getline(Alumno1.apellido,50);
    cout<<"Ingrese la edad del Alumno: ";  
    cin>>Alumno1.edad;
    cout<<"Ingrese su profesion: ";
    cin.getline(Alumno1.profesion,50);
    cout<<"Ingrese el lugar de nacimiento del Alumno: ";
    cin.getline(Alumno1.lugar_nacimiento,50);
    cout<<"Ingrese la direccion del Alumno: ";
    cin.getline(Alumno1.direccion,100);
    cin.ignore();
    cout<<"Ingrese el telefono del Alumno: ";
    cin>>Alumno1.telefono;

    return Alumno1;
    
}
void mostrarAlumno(Alumno Alumno1){
    cout<<"Cedula: "<<Alumno1.cedula<<endl;
    cout<<"Nombre: "<<Alumno1.nombre<<endl;
    cout<<"Apellido: "<<Alumno1.apellido<<endl;
    cout<<"edad: "<<Alumno1.edad<<endl;
    cout<<"Profesion: "<<Alumno1.profesion<<endl;
    cout<<"Lugar de nacimiento: "<<Alumno1.lugar_nacimiento<<endl;
    cout<<"Direccion: "<<Alumno1.direccion<<endl;
    cout<<"Telefono: "<<Alumno1.telefono<<endl;

    
}