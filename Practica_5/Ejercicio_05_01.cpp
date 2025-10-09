// Materia: Programación I, Paralelo 4
// Autor: Gabriel ALejandro Pacheco Quispe.
// Fecha creación: 29/09/2025
// Número de ejercicio: 1
// Problema planteado:
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
vector<double> generar_voltajes() {
    vector<double> voltajes;
    srand(time(0));

    for(int i = 0; i < 100; i++) {
        voltajes.push_back(rand() % (100-20+1) + 20);
    }
    return voltajes;
}
vector<double> generar_temperaturas() {
    vector<double> temperaturas;
    srand(time(0));

    for(int i = 0; i < 50; i++) {
        temperaturas.push_back(rand() % (100-0+1));
    }
    return temperaturas;
}
vector<char> generar_caracteres() {
    vector<char> caracteres;
    srand(time(0));

    for(int i = 0; i < 30; i++) {
        caracteres.push_back(rand() % (255) + 1);
    }
    return caracteres;
}
vector<int> generar_años() {
    vector<int> anios;
    srand(time(0));

    for(int i = 0; i < 100; i++) {
        anios.push_back(rand() % (2025+1-1990) + 1990);
    }
    return anios;
}
vector<double> generar_velocidades() {
    vector<double> velocidades;
    srand(time(0));

    for(int i = 0; i < 32; i++) {
        velocidades.push_back(rand() % (300+1-10) + 10);
    }
    return velocidades;
}
vector<double> generar_distancias() {
    vector<double> distancias;
    srand(time(0));

    for(int i = 0; i < 1000; i++) {
        distancias.push_back(rand() % (1000+1-1) + 1);
    }
    return distancias;
}

int main(){
    vector<double> voltajes = generar_voltajes();
    vector<double> temperaturas = generar_temperaturas();
    vector<char> caracteres = generar_caracteres();
    vector<int> anios = generar_años();
    vector<double> velocidades = generar_velocidades();
    vector<double> distancias = generar_distancias();

    cout << "Voltajes generados: ";
    for(double v : voltajes) {
        cout << v << " ";
    }
    cout << "\n\n";

    cout << "Temperaturas generadas: ";
    for(double t : temperaturas) {
        cout << t << " ";
    }
    cout << "\n\n";

    cout << "Caracteres generados: ";
    for(char c : caracteres) {
        cout << c << " ";
    }
    cout << "\n\n";

    cout << "Años generados: ";
    for(int a : anios) {
        cout << a << " ";
    }
    cout << "\n\n";

    cout << "Velocidades generadas: ";
    for(double ve : velocidades) {
        cout << ve << " ";
    }
    cout << "\n\n";

    cout << "Distancias generadas: ";
    for(double d : distancias) {
        cout << d << " ";
    }
    cout << "\n\n";

    return 0;
}