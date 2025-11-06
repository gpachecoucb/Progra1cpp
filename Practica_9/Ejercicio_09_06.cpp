// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco.
// Fecha creación: 06/11/2025
// Número de ejercicio: 6
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct empleado 
{
    char nombre[50];
    char id[50];
    double sueldo;
    int antiguedad;

};
empleado Agregarempleado();
void mostrarempleado(empleado empleado1);
void mostrarEmpleadosSueldo(vector<empleado> empleados, double sueldoMinimo);
double calcularPromedioAntiguedad(vector<empleado> empleados);
int main()
{
    vector<empleado> empleados;
    int n;
    string directorBuscado;
    string generoBuscado;
    cout<<"Ingrese el número de empleados: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del empleado "<<i+1<<":"<<endl;
        empleado empleado = Agregarempleado();
        empleados.push_back(empleado);
    }
    double sueldoMinimo;
    cout<<"Ingrese el sueldo minimo para filtrar empleados: ";
    cin>>sueldoMinimo;
    cout<<"Empleados con sueldo mayor a "<<sueldoMinimo<<":"<<endl;
    mostrarEmpleadosSueldo(empleados, sueldoMinimo);
    double promedioAntiguedad = calcularPromedioAntiguedad(empleados);
    cout<<"El promedio de antiguedad de los empleados es: "<<promedioAntiguedad<<endl;
    
    
   
    return 0;
}
empleado Agregarempleado(){
    struct empleado empleado1;
    cout <<"Ingrese el nombre del empleado: ";
    cin.getline(empleado1.nombre,50);
    cout<<"Ingrese el ID del empleado: ";
    cin.getline(empleado1.id,50);
    cout<<"Ingrese el sueldo del empleado: ";
    cin>>empleado1.sueldo;
    cout<<"Ingrese la antiguedad del empleado (en años): ";
    cin>>empleado1.antiguedad;
    cin.ignore();
    
    

    return empleado1;
    
}
void mostrarempleado(empleado empleado1){
    cout<<"Nombre: "<<empleado1.nombre<<endl;
    cout<<"ID: "<<empleado1.id<<endl;
    cout<<"Sueldo: "<<empleado1.sueldo<<endl;
    cout<<"Antiguedad (en años): "<<empleado1.antiguedad<<endl;

    
}
void mostrarEmpleadosSueldo(vector<empleado> empleados, double sueldoMinimo){
    for(size_t i = 0; i < empleados.size(); i++){
        if(empleados[i].sueldo > sueldoMinimo){
            mostrarempleado(empleados[i]);
        }
    }
}
double calcularPromedioAntiguedad(vector<empleado> empleados){
    double sumaAntiguedad = 0;
    for(size_t i = 0; i < empleados.size(); i++){
        sumaAntiguedad += empleados[i].antiguedad;
    }
    return sumaAntiguedad / empleados.size();
}