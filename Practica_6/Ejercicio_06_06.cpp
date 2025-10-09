// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 6
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    float rango1 = 0;
    float rango2 = 0;
    float rango3 = 0;
    float rango4 = 0;
    srand(time(0));
    vector <int> notas_estudiantes;
    int n = 0;
    cout << "ingrese la cantidad de notas" << endl;
    cin >> n;
    int nota = 0;
    for(int i = 0; i<n; i++){
        nota = (rand()%(100+1-1))+1;
        notas_estudiantes.push_back(nota);
        
    }
    cout << endl;
    for(int i = 0; i<notas_estudiantes.size(); i++){
        cout << notas_estudiantes[i] << " ";
        if(notas_estudiantes[i] >= 0 && notas_estudiantes[i] <=59){
            rango1 ++;
        }
        else if(notas_estudiantes[i] >= 60 && notas_estudiantes[i] <=79){
            rango2 ++;
        }
        else if(notas_estudiantes[i] >= 80 && notas_estudiantes[i] <=89){
            rango3 ++;
        }
        else{
            rango4 ++;
        }
        
    }
    cout << endl;
    cout << "Porcentaje de grados de la nota" << endl;
    cout << "Reprobados " << rango1/notas_estudiantes.size()*100 << "%" <<endl; 
    cout << "Regulares " << rango2/notas_estudiantes.size()*100 << "%"<<endl; 
    cout << "Buenos " << rango3/notas_estudiantes.size()*100 << "%"<<endl; 
    cout << "Excelentes " << rango4/notas_estudiantes.size() *100<< "%"<<endl; 
    
    cout << endl;
    
    return 0;
}