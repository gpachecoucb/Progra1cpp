// Materia: Programación I, Paralelo 1
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 8/10/2024
// Número de ejercicio: 7
// Problema planteado:
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int rango1 = 0;
    int rango2 = 0;
    int rango3 = 0;
    int rango4 = 0;
    int rango5 = 0;
    int rango6 = 0;
    int rango7 = 0;
    int rango8 = 0;
    int rango9 = 0;
    int rango10 = 0;
    
    srand(time(0));
    vector <int> escala_grises;
    int n = 0;
    cout << "ingrese la cantidad de notas" << endl;
    cin >> n;
    int numero = 0;
    for(int i = 0; i<n; i++){
        numero = (rand()%(100+1-1))+1;
        escala_grises.push_back(numero);
        
    }
    cout << endl;
    int m;
    for(int i = 0; i<n; i++){
        m = escala_grises[i];
        cout << escala_grises[i] << " ";
        if(m >= 0 && m < 10){
            rango1++;
        }
        else if(m >= 10 && m < 20){
            rango2++;
        }
        else if(m >= 20 && m < 30){
            rango3++;
        }
        else if(m >= 30 && m < 40){
            rango4++;
        }
        else if(m >= 40 && m < 50){
            rango5++;
        }
        else if(m >= 50 && m < 60){
            rango6++;
        }
        else if(m>= 60 && m < 70){
            rango7++;
        }
        else if(m >= 70 && m < 80){
            rango8++;
        }
        else if(m >= 80 && m < 90){
            rango9++;
        }
        else{
            rango10++;
        }
        
    }
    cout << "cantidad de pixeles en escalas de 10" << endl;
    cout << "0-9 " << rango1<< " pixeles"<< endl;
    cout << "10-19 " << rango2<< " pixeles"<< endl;
    cout << "20-29 " << rango3<< " pixeles"<< endl;
    cout << "30-39 " << rango4<< " pixeles"<< endl;
    cout << "40-49 " << rango5<< " pixeles"<< endl;
    cout << "50-59 " << rango6<< " pixeles"<< endl;
    cout << "60-69 " << rango7<< " pixeles"<< endl;
    cout << "70-79 " << rango8<< " pixeles"<< endl;
    cout << "80-89 " << rango9<< " pixeles"<< endl;
    cout << "90-99 " << rango1<< " pixeles"<< endl;
    
    
    return 0;
}