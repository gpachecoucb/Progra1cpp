// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 08/09/2025
// Número de ejercicio: 2

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    int aleatorio, n;
    float sumacaras = 0, sumacruz = 0;
    srand(time(0));
    aleatorio = rand() % (2);
    cout << "Numero de lanzamientos de la moneda: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        aleatorio = rand() % (2);
        if (aleatorio == 0) {
            cout << "Cara" << endl;
            sumacaras++;
        } else {
            cout << "Cruz" << endl;
            sumacruz++;

        }
    }
    cout << "Promedio de caras: " << sumacaras/n * 100 << "%" << endl;
    cout << "Promedio de cruces: " << sumacruz/n * 100 << "%" << endl;
    
    
    return 0;
}
