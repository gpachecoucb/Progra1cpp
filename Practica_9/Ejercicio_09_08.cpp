// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco
// Fecha creación: 06/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct atleta
{
    char nombre[50];
    char departamento[50];
    char deporte[50];
    int medallas;
};

atleta AgregarAtleta();
void mostrarAtleta(atleta a);
void mostrarMedallero(vector<atleta> atletas);

int main()
{
    vector<atleta> atletas;
    int n;

    cout << "===== OLIMPIADA NACIONAL =====" << endl;
    cout << "Ingrese el número de atletas a registrar: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "\nIngrese los datos del atleta " << i + 1 << ":" << endl;
        atleta a = AgregarAtleta();
        atletas.push_back(a);
    }

    cout << "\n===== LISTA DE ATLETAS REGISTRADOS =====" << endl;
    for (int i = 0; i < atletas.size(); i++)
    {
        mostrarAtleta(atletas[i]);
        cout << "-------------------------------------" << endl;
    }

    cout << "\n===== MEDALLERO FINAL POR DEPARTAMENTO =====" << endl;
    mostrarMedallero(atletas);

    return 0;
}

atleta AgregarAtleta()
{
    atleta a;
    cout << "Nombre del atleta: ";
    cin.getline(a.nombre, 50);
    cout << "Departamento que representa: ";
    cin.getline(a.departamento, 50);
    cout << "Deporte que practica: ";
    cin.getline(a.deporte, 50);
    cout << "Cantidad de medallas ganadas: ";
    cin >> a.medallas;
    cin.ignore();
    return a;
}

void mostrarAtleta(atleta a)
{
    cout << "Nombre: " << a.nombre << endl;
    cout << "Departamento: " << a.departamento << endl;
    cout << "Deporte: " << a.deporte << endl;
    cout << "Medallas ganadas: " << a.medallas << endl;
}

void mostrarMedallero(vector<atleta> atletas)
{
    struct Medallero
    {
        string departamento;
        int totalMedallas;
    };
    vector<Medallero> medallero;
    for (int i = 0; i < atletas.size(); i++)
    {
        string depto = atletas[i].departamento;
        bool encontrado = false;

        for (int j = 0; j < medallero.size(); j++)
        {
            if (medallero[j].departamento == depto)
            {
                medallero[j].totalMedallas += atletas[i].medallas;
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            Medallero nuevo;
            nuevo.departamento = depto;
            nuevo.totalMedallas = atletas[i].medallas;
            medallero.push_back(nuevo);
        }
    }
    for (int i = 0; i < medallero.size(); i++)
    {
        cout << "Departamento: " << medallero[i].departamento
             << " | Total de medallas: " << medallero[i].totalMedallas << endl;
    }
}