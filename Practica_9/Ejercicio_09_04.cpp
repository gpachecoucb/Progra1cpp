// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco.
// Fecha creación: 06/11/2025
// Número de ejercicio: 4
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
struct empleado
{
    
    char nombre[50];
    char genero[50];
    double salario;

};
empleado Agregarempleado();
void mostrarempleado(empleado empleado1);
empleado empleadoMenorSalario(vector<empleado> empleados);
empleado empleadoMayorSalario(vector<empleado> empleados);

int main()
{
    vector<empleado> empleados;
    int n;
    cout<<"Ingrese el número de empleados: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del empleado "<<i+1<<":"<<endl;
        empleado empleado = Agregarempleado();
        empleados.push_back(empleado);
    }
    for(int i = 0; i < n; i++){
        cout<<"Datos del empleado "<<i+1<<":"<<endl;
        mostrarempleado(empleados[i]);
    }
    empleado menorSalario = empleadoMenorSalario(empleados);
    cout<<"El empleado con el menor salario es:"<<endl;
    mostrarempleado(menorSalario);
    empleado mayorSalario = empleadoMayorSalario(empleados);
    cout<<"El empleado con el mayor salario es:"<<endl;
    mostrarempleado(mayorSalario);

    
    return 0;
}
empleado empleadoMenorSalario(vector<empleado> empleados){
    empleado mejorempleado = empleados[0];
    for(size_t i = 1; i < empleados.size(); i++){
        if(empleados[i].salario < mejorempleado.salario){
            mejorempleado = empleados[i];
        }
    }
    return mejorempleado;
}
empleado empleadoMayorSalario(vector<empleado> empleados){
    int mayor = 0;
    empleado mejorempleado;
    for(int i = 0; i < empleados.size(); i++){
        if(empleados[i].salario > mayor){
            mayor = empleados[i].salario;
            mejorempleado = empleados[i];
        }
    }
    return mejorempleado;
}


empleado Agregarempleado(){
    struct empleado empleado1;
    cout <<"Ingrese el nombre del empleado: ";
    cin.getline(empleado1.nombre,50);
    cout<<"Ingrese el genero del empleado: ";
    cin.getline(empleado1.genero,50);
    
    cout<<"Ingrese el salario del empleado: ";
    cin>>empleado1.salario;
    cin.ignore();
    

    return empleado1;
    
}
void mostrarempleado(empleado empleado1){
    cout<<"Nombre: "<<empleado1.nombre<<endl;
    cout<<"Genero: "<<empleado1.genero<<endl;
    cout<<"Salario: "<<empleado1.salario<<endl;

    
}