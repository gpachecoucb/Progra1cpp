// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 9
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int horas_jornada_laboral(int hora);
int main(){
    int minutos, hora;

    cout << "Ingrese los minutos de la jornada laboral de hoy: ";
    cin >> minutos;
    hora = minutos/60;
    cout << "Usted ha trabajado " << hora << " horas y " << minutos % 60 << " minutos hoy." << endl;
    if(horas_jornada_laboral(minutos) == 0){
        cout << "Ha cumplido con su jornada laboral de 8 horas." << endl;
    }
    if(horas_jornada_laboral(minutos) < 0){
        cout << "Le faltan " << horas_jornada_laboral(minutos) / 60 * -1 << " horas y " << horas_jornada_laboral(minutos) * -1 % 60<<" minutos para completar su jornada laboral de 8 horas." << endl;
    }
    if(horas_jornada_laboral(minutos) > 0){
        cout << "Tiempo extra en la jornada de hoy:" << endl;
        cout <<  horas_jornada_laboral(minutos)/60 << " horas." << endl;
        cout << horas_jornada_laboral(minutos)%60 << " minutos." << endl;
    }
    return 0;
}
int horas_jornada_laboral(int minutos){
    if(minutos == 8*60){
        return 0; 
    }
    else if(minutos < 8*60){
        return minutos - 8*60;
    }
    else if(minutos > 8*60){
        return minutos - 8*60;
    }
    else{
        return -1; 
    }
}