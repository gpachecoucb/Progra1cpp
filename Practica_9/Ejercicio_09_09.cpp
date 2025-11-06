// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco
// Fecha creación: 06/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct alumno
{
    char nombre[50];
    float T1, T2, T3, T4, EF;
    float NP; // Nota de presentación
    float NF; // Nota final
};


alumno AgregarAlumno();
void mostrarAlumno(alumno a);
void mostrarResultados(vector<alumno> alumnos);

int main()
{
    vector<alumno> alumnos;
    int n;

    cout << "===== CALIFICACIONES DEL CURSO =====" << endl;
    cout << "Ingrese el número de alumnos: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "\nIngrese los datos del alumno " << i + 1 << ":" << endl;
        alumno a = AgregarAlumno();
        alumnos.push_back(a);
    }

    cout << "\n===== LISTA DE ALUMNOS Y NOTAS =====" << endl;
    for (int i = 0; i < alumnos.size(); i++)
    {
        mostrarAlumno(alumnos[i]);
        cout << "-----------------------------------" << endl;
    }

    cout << "\n===== ESTADÍSTICAS DEL CURSO =====" << endl;
    mostrarResultados(alumnos);

    return 0;
}
alumno AgregarAlumno()
{
    alumno a;
    cout << "Nombre del alumno: ";
    cin.getline(a.nombre, 50);
    cout << "Ingrese la nota de T1: ";
    cin >> a.T1;
    cout << "Ingrese la nota de T2: ";
    cin >> a.T2;
    cout << "Ingrese la nota de T3: ";
    cin >> a.T3;
    cout << "Ingrese la nota de T4: ";
    cin >> a.T4;
    cout << "Ingrese la nota del Examen Final (EF): ";
    cin >> a.EF;
    cin.ignore();

    a.NP = (a.T1 + a.T2 + a.T3 + a.T4) / 4;
    a.NF = 0.7 * a.NP + 0.3 * a.EF;

    return a;
}
void mostrarAlumno(alumno a)
{
    cout << "Nombre: " << a.nombre << endl;
    cout << "T1: " << a.T1 << " | T2: " << a.T2 << " | T3: " << a.T3 << " | T4: " << a.T4 << endl;
    cout << "Examen Final (EF): " << a.EF << endl;
    cout << "Nota de presentación (NP): " << a.NP << endl;
    cout << "Nota Final (NF): " << a.NF << endl;
}
void mostrarResultados(vector<alumno> alumnos)
{
    float suma = 0;
    float min = alumnos[0].NF;
    float max = alumnos[0].NF;

    for (int i = 0; i < alumnos.size(); i++)
    {
        suma += alumnos[i].NF;

        if (alumnos[i].NF < min)
            min = alumnos[i].NF;
        if (alumnos[i].NF > max)
            max = alumnos[i].NF;
    }

    float promedio = suma / alumnos.size();

    cout << "Promedio del curso: " << promedio << endl;
    cout << "Nota mínima: " << min << endl;
    cout << "Nota máxima: " << max << endl;
}