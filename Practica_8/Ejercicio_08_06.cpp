// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe.
// Fecha creación: 23/10/2025
// Número de ejercicio: 6
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int vector_igual(vector<int> a, vector<int> b, int n);
int main(){
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {1, 2, 3, 4, 5};
    int n = vec1.size();
    if(vector_igual(vec1, vec2, n)){
        cout << "Los vectores son iguales." << endl;
    } else {
        cout << "Los vectores no son iguales." << endl;
    }
    return 0;
}
int vector_igual(vector<int> a, vector<int> b, int n){
    if(n == 0){
        return 1; 
    }
    if(a[n-1] != b[n-1]){
        return 0; 
    }
    return vector_igual(a, b, n-1);
}