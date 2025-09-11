// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 10/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int generar_edad(int rand);
int generar_estatura(int rand);
int media_edad(int suma, int nro_edades);
int mayor_18(int edad);
int estatura_mayor_175(int estatura);

int main(){
    int nro_personas;
    int suma_edades = 0;
    int contador_mayores_18 = 0;
    int contador_estatura_mayor_175 = 0;
    int edad, estatura;
    cout << "Ingrese el número de personas: ";
    cin >> nro_personas;
    srand(time(0));
    for(int i = 1; i <= nro_personas; i++){
        
        edad = generar_edad(rand());
        estatura = generar_estatura(rand());
        cout << "Persona " << i << ": Edad = " << edad << " años, Estatura = " << estatura << " cm" << endl;
        suma_edades += edad;
        contador_mayores_18 += mayor_18(edad);
        contador_estatura_mayor_175 += estatura_mayor_175(estatura);
        
    }
    cout << "La media de edades es: " << media_edad(suma_edades, nro_personas) << " años" << endl;
    cout << "Número de personas mayores de 18 años: " << contador_mayores_18 << endl;
    cout << "Número de personas con estatura mayor a 1.75 metros: " << contador_estatura_mayor_175 << endl;

    
    return 0;
}
int generar_edad(int rand){
    int edad = rand % (35 - 1 + 1) + 1;
    return edad;
    
}
int generar_estatura(int rand){
    
    int estatura = rand % (121) + 80;
    return estatura;
}
int media_edad(int suma, int nro_edades){
    return suma / nro_edades;
}
int mayor_18(int edad){
    if(edad > 18){
        return 1; 
    }else{
        return 0; 
    }
}
int estatura_mayor_175(int estatura){
    if(estatura > 175){
        return 1; 
    }else{
        return 0; 
    }
}
