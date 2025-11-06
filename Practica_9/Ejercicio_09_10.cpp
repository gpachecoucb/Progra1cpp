// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco
// Fecha creación: 06/11/2025
// Número de ejercicio: 10

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

struct Fraccion
{
    int numerador;
    int denominador;
};

Fraccion AgregarFraccion();
void mostrarFraccion(Fraccion f);
int MCD(int a, int b);
Fraccion ReducirFraccion(Fraccion f);

int main()
{
    Fraccion f, fraccionSimplificada;

    cout << "===== REDUCIR FRACCIÓN =====" << endl;
    f = AgregarFraccion();

    cout << "\nFracción original: ";
    mostrarFraccion(f);

    fraccionSimplificada = ReducirFraccion(f);

    cout << "Fracción simplificada: ";
    mostrarFraccion(fraccionSimplificada);

    return 0;
}

Fraccion AgregarFraccion()
{
    Fraccion f;
    cout << "Ingrese el numerador: ";
    cin >> f.numerador;
    cout << "Ingrese el denominador: ";
    cin >> f.denominador;
    while (f.denominador == 0)
    {
        cout << "El denominador no puede ser 0. Ingrese nuevamente: ";
        cin >> f.denominador;
    }

    return f;
}
void mostrarFraccion(Fraccion f)
{
    cout << f.numerador << "/" << f.denominador << endl;
}
int MCD(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

Fraccion ReducirFraccion(Fraccion f)
{
    Fraccion simplificada;
    int divisor = MCD(f.numerador, f.denominador);

    simplificada.numerador = f.numerador / divisor;
    simplificada.denominador = f.denominador / divisor;

    return simplificada;
}