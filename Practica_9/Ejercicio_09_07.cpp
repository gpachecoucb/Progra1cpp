// Materia: Programación I, Paralelo 4
// Autor: Gabriel Pacheco.
// Fecha creación: 06/11/2025
// Número de ejercicio: 7
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct producto 
{
    char nombre[50];
    char codigo[50];
    double precio;
    int cantidad_en_inventario;
    char observaciones[100];

};
producto Agregarproducto();
void mostrarproducto(producto producto1);
producto productoMasCaro(vector<producto> productos);
int CantidadProductos(vector<producto> productos);
int main()
{
    vector<producto> productos;
    int n;
    string directorBuscado;
    string generoBuscado;
    cout<<"Ingrese el número de productos: ";
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout<<"Ingrese los datos del producto "<<i+1<<":"<<endl;
        producto producto = Agregarproducto();
        productos.push_back(producto);
    }
    producto producto_caro = productoMasCaro(productos);
    cout << "el producto más caro es: " << endl;
    mostrarproducto(producto_caro);
    cout << "la cantidad total de productos en inventario es " << endl;
    cout << CantidadProductos(productos);
    
    return 0;
}
producto Agregarproducto(){
    struct producto producto1;
    cout <<"Ingrese el nombre del producto: ";
    cin.getline(producto1.nombre,50);
    cout<<"Ingrese el codigo del producto: ";
    cin.getline(producto1.codigo,50);
    cout<<"Ingrese el precio del producto: ";
    cin>>producto1.precio;
    cout<<"Ingrese la cantidad en inventario del producto: ";
    cin>>producto1.cantidad_en_inventario;
    cin.ignore();
    if(producto1.cantidad_en_inventario <= 5){
        strcpy(producto.observaciones, "Producto con baja cantidad en inventario")
    }
    else{
        strcpy(producto.observaciones, "")
    }
    return producto1;
}
void mostrarproducto(producto producto1){
    cout<<"Nombre: "<<producto1.nombre<<endl;
    cout<<"Código: "<<producto1.codigo<<endl;
    cout<<"Precio: "<<producto1.precio<<endl;
    cout<<"Cantidad en inventario: "<<producto1.cantidad_en_inventario<<endl;
    cout<<"Observaciones: "<<producto1.observaciones<<endl;
}
producto productoMasCaro(vector<producto> productos){
    int mayor = 0;
    producto mejorproducto;
    for(int i = 0; i < productos.size(); i++){
        if(productos[i].precio > mayor){
            mayor = productos[i].precio;
            mejorproducto = productos[i];
        }
    }
    return mejorproducto;
}
int CantidadProductos(vector<producto> productos){
    int suma = 0;
    for(int i = 0; i <= productos.size(); i++){
        suma+=productos[i].cantidad_en_inventario;
    } 
    return suma;
}