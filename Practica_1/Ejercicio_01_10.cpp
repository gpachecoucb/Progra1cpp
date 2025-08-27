#include <iostream>
using namespace std;
// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 10
int main()
{
    int nota = 0;
    cout << "INGRESA LA NOTA DEL ESTUDIANTE;";    
    cin >> nota;
    if (nota >= 51){
        if (nota < 60){
            cout << "Tiene la calificacion de C";
        }
        else if (nota < 70){
            cout << "Tiene la calificacion de C+";
        }
        else if (nota < 80){
            cout << "Tiene la calificacion de B";
        }
        else if (nota < 90){
            cout << "Tiene la calificacion de B+";
        }
        else if (nota < 95){
            cout << "Tiene la calificacion de A";
        }
        
        else if (nota <= 100){
            cout << "Tiene la calificacion de A+";
        }
        else{
            cout << "Nota invalida";
        }
    }
    else
    {
        cout << "REPROBADO";
    }
    return 0;
}