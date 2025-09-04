// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe
// Carnet: 9099972 L.P.
// Carrera del estudiante: Ingeniería de Sistemas
// Fecha creación: 27/08/2025
// Número de ejercicio: 18
#include <iostream>
using namespace std;
int main()

{
    cout << "Los primero 100 numeros primos son: " << endl;
    int contador = 2;
    int contadorglob = 0;
    int contadordiv;
    while (contadorglob < 100)
    {
        contadordiv = 0;
        for(int i = 1; i < contador; i++){
            
            if(contador % i == 0){
                contadordiv++;
            }
        }
        if(contadordiv == 1){
            contadorglob++;
            cout << contadorglob << ": " << contador << endl;
            
        }
        contador++;
        
    }
    
    return 0;
}