// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe .
// Fecha creación: 11-11-2025
// Número de ejercicio: 1
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Estructura para productos
struct Producto {
    int codigo;
    char nombre[50];
    int cantidadInicial;
    double precio;
};

// Estructura para ventas
struct Venta {
    char ci[15];
    char nombreCliente[50];
    int codigoProducto;
    int cantidad;
};

// Nombres de archivos
const char* ARCHIVO_PRODUCTOS = "PRODUCTOS.BIN";
const char* ARCHIVO_VENTAS = "VENTAS.txt";

// Funciones del programa
void adicionarProducto();
void listadoProductos();
void buscarProductoPorCodigo();
void modificarProducto();
void adicionarVenta();
void mostrarMenu();
bool existeProducto(int codigo);
void guardarProducto(const Producto& producto);
void leerProductos(vector<Producto>& productos);
void guardarVentaEnTexto(const Venta& venta);
void leerVentas(vector<Venta>& ventas);
int obtenerCantidadVendida(int codigoProducto);
void parsearLineaVenta(const char* linea, Venta& venta);

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                adicionarProducto();
                break;
            case 2:
                listadoProductos();
                break;
            case 3:
                buscarProductoPorCodigo();
                break;
            case 4:
                modificarProducto();
                break;
            case 5:
                adicionarVenta();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        
        cout << endl;
    } while(opcion != 6);
    
    return 0;
}

void mostrarMenu() {
    cout << "=================================" << endl;
    cout << "     SISTEMA FARMACIAS CHAVEZ" << endl;
    cout << "=================================" << endl;
    cout << "1. Adicionar Producto" << endl;
    cout << "2. Listado de Productos" << endl;
    cout << "3. Buscar producto por codigo" << endl;
    cout << "4. Modificar producto" << endl;
    cout << "5. Adicionar ventas del producto" << endl;
    cout << "6. Salir" << endl;
    cout << "=================================" << endl;
}

void adicionarProducto() {
    Producto nuevo;
    
    cout << "\n--- ADICIONAR PRODUCTO ---" << endl;
    
    cout << "Codigo del producto: ";
    cin >> nuevo.codigo;
    
    // Verificar si el producto ya existe
    if(existeProducto(nuevo.codigo)) {
        cout << "Error: Ya existe un producto con este codigo." << endl;
        return;
    }
    
    cin.ignore(); // Limpiar buffer
    cout << "Nombre del producto: ";
    cin.getline(nuevo.nombre, 50);
    
    cout << "Cantidad inicial: ";
    cin >> nuevo.cantidadInicial;
    
    cout << "Precio unitario: ";
    cin >> nuevo.precio;
    
    // Guardar en archivo binario
    guardarProducto(nuevo);
    
    cout << "Producto registrado exitosamente!" << endl;
}

void listadoProductos() {
    vector<Producto> productos;
    vector<Venta> ventas;
    
    // Leer productos del archivo binario
    leerProductos(productos);
    
    if(productos.empty()) {
        cout << "\nNo hay productos registrados." << endl;
        return;
    }
    
    // Leer ventas del archivo de texto
    leerVentas(ventas);
    
    cout << "\n====================================================================================================" << endl;
    cout << "                                LISTADO DE PRODUCTOS" << endl;
    cout << "====================================================================================================" << endl;
    cout << left << setw(8) << "CODIGO" 
         << setw(25) << "NOMBRE PRODUCTO" 
         << setw(18) << "CANTIDAD INICIAL" 
         << setw(10) << "PRECIO" 
         << setw(18) << "CANTIDAD VENDIDA" 
         << setw(10) << "TOTAL" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    
    double totalGeneral = 0;
    
    for(const auto& producto : productos) {
        int cantidadVendida = obtenerCantidadVendida(producto.codigo);
        double totalVendido = cantidadVendida * producto.precio;
        totalGeneral += totalVendido;
        
        cout << left << setw(8) << producto.codigo
             << setw(25) << producto.nombre
             << setw(18) << producto.cantidadInicial
             << setw(10) << fixed << setprecision(2) << producto.precio
             << setw(18) << cantidadVendida
             << setw(10) << fixed << setprecision(2) << totalVendido << endl;
    }
    
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "TOTAL GENERAL DE VENTAS: $" << fixed << setprecision(2) << totalGeneral << endl;
    cout << "====================================================================================================" << endl;
}

void buscarProductoPorCodigo() {
    int codigo;
    cout << "\n--- BUSCAR PRODUCTO POR CODIGO ---" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    
    ifstream archivo(ARCHIVO_PRODUCTOS, ios::binary);
    
    if(!archivo) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    
    Producto producto;
    bool encontrado = false;
    
    while(archivo.read((char*)&producto, sizeof(Producto))) {
        if(producto.codigo == codigo) {
            encontrado = true;
            cout << "\nPRODUCTO ENCONTRADO:" << endl;
            cout << "-------------------" << endl;
            cout << "Codigo: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Cantidad inicial: " << producto.cantidadInicial << endl;
            cout << "Precio: $" << fixed << setprecision(2) << producto.precio << endl;
            
            // Calcular cantidad vendida
            int cantidadVendida = obtenerCantidadVendida(codigo);
            cout << "Cantidad vendida: " << cantidadVendida << endl;
            cout << "Stock actual: " << (producto.cantidadInicial - cantidadVendida) << endl;
            break;
        }
    }
    
    archivo.close();
    
    if(!encontrado) {
        cout << "Producto con codigo " << codigo << " no encontrado." << endl;
    }
}

void modificarProducto() {
    int codigo;
    cout << "\n--- MODIFICAR PRODUCTO ---" << endl;
    cout << "Ingrese el codigo del producto a modificar: ";
    cin >> codigo;
    
    if(!existeProducto(codigo)) {
        cout << "Error: No existe un producto con este codigo." << endl;
        return;
    }
    
    // Leer todos los productos
    vector<Producto> productos;
    leerProductos(productos);
    
    // Buscar el producto a modificar
    bool modificado = false;
    for(auto& producto : productos) {
        if(producto.codigo == codigo) {
            cout << "\nProducto actual:" << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Cantidad inicial: " << producto.cantidadInicial << endl;
            cout << "Precio: $" << producto.precio << endl;
            
            cout << "\nIngrese los nuevos datos:" << endl;
            cin.ignore();
            cout << "Nuevo nombre: ";
            cin.getline(producto.nombre, 50);
            
            cout << "Nueva cantidad inicial: ";
            cin >> producto.cantidadInicial;
            
            cout << "Nuevo precio: ";
            cin >> producto.precio;
            
            modificado = true;
            break;
        }
    }
    
    if(modificado) {
        // Guardar todos los productos de nuevo (sobreescribir archivo)
        ofstream archivo(ARCHIVO_PRODUCTOS, ios::binary);
        for(const auto& producto : productos) {
            archivo.write((char*)&producto, sizeof(Producto));
        }
        archivo.close();
        
        cout << "Producto modificado exitosamente!" << endl;
    }
}

void adicionarVenta() {
    Venta nuevaVenta;
    int codigoProducto;
    
    cout << "\n--- ADICIONAR VENTA ---" << endl;
    
    cin.ignore(); // Limpiar buffer
    cout << "CI del cliente: ";
    cin.getline(nuevaVenta.ci, 15);
    
    cout << "Nombre del cliente: ";
    cin.getline(nuevaVenta.nombreCliente, 50);
    
    cout << "Codigo del producto: ";
    cin >> codigoProducto;
    
    // Verificar si el producto existe
    if(!existeProducto(codigoProducto)) {
        cout << "Error: No existe un producto con este codigo." << endl;
        return;
    }
    
    // Buscar el producto para verificar stock
    vector<Producto> productos;
    leerProductos(productos);
    Producto productoVendido;
    bool productoEncontrado = false;
    
    for(const auto& producto : productos) {
        if(producto.codigo == codigoProducto) {
            productoVendido = producto;
            productoEncontrado = true;
            break;
        }
    }
    
    if(!productoEncontrado) {
        cout << "Error al buscar el producto." << endl;
        return;
    }
    
    cout << "Cantidad a vender: ";
    cin >> nuevaVenta.cantidad;
    
    // Verificar stock disponible
    int cantidadVendida = obtenerCantidadVendida(codigoProducto);
    int stockDisponible = productoVendido.cantidadInicial - cantidadVendida;
    
    if(nuevaVenta.cantidad > stockDisponible) {
        cout << "Error: Stock insuficiente." << endl;
        cout << "Stock disponible: " << stockDisponible << endl;
        return;
    }
    
    nuevaVenta.codigoProducto = codigoProducto;
    
    // Guardar venta en archivo de texto
    guardarVentaEnTexto(nuevaVenta);
    
    cout << "Venta registrada exitosamente!" << endl;
    cout << "Total: $" << fixed << setprecision(2) << (nuevaVenta.cantidad * productoVendido.precio) << endl;
}

bool existeProducto(int codigo) {
    ifstream archivo(ARCHIVO_PRODUCTOS, ios::binary);
    
    if(!archivo) {
        return false; // Si el archivo no existe, no hay productos
    }
    
    Producto temp;
    while(archivo.read((char*)&temp, sizeof(Producto))) {
        if(temp.codigo == codigo) {
            archivo.close();
            return true;
        }
    }
    
    archivo.close();
    return false;
}

void guardarProducto(const Producto& producto) {
    ofstream archivo(ARCHIVO_PRODUCTOS, ios::binary | ios::app);
    
    if(archivo) {
        archivo.write((char*)&producto, sizeof(Producto));
        archivo.close();
    } else {
        cout << "Error al guardar el producto." << endl;
    }
}

void leerProductos(vector<Producto>& productos) {
    ifstream archivo(ARCHIVO_PRODUCTOS, ios::binary);
    
    if(archivo) {
        Producto temp;
        while(archivo.read((char*)&temp, sizeof(Producto))) {
            productos.push_back(temp);
        }
        archivo.close();
    }
}

void guardarVentaEnTexto(const Venta& venta) {
    ofstream archivo(ARCHIVO_VENTAS, ios::app);
    
    if(archivo) {
        archivo << venta.ci << "; " 
                << venta.nombreCliente << "; " 
                << venta.codigoProducto << "; " 
                << venta.cantidad << endl;
        archivo.close();
    } else {
        cout << "Error al guardar la venta." << endl;
    }
}

void parsearLineaVenta(const char* linea, Venta& venta) {
    char tempLinea[200];
    strcpy(tempLinea, linea);
    
    // Buscar primer punto y coma (CI)
    char* token = strtok(tempLinea, ";");
    if(token != NULL) {
        // Eliminar espacios al inicio y final del token
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(venta.ci, token, 14);
        venta.ci[14] = '\0';
    }
    
    // Buscar segundo punto y coma (Nombre)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios al inicio
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(venta.nombreCliente, token, 49);
        venta.nombreCliente[49] = '\0';
    }
    
    // Buscar tercer punto y coma (Código producto)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        venta.codigoProducto = atoi(token);
    }
    
    // Buscar cuarto punto y coma (Cantidad) - puede ser el final de línea
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        venta.cantidad = atoi(token);
    } else {
        // Si no hay más punto y coma, intentar con el resto de la línea
        token = strtok(NULL, "\n");
        if(token != NULL) {
            while(*token == ' ') token++;
            venta.cantidad = atoi(token);
        }
    }
}

void leerVentas(vector<Venta>& ventas) {
    ifstream archivo(ARCHIVO_VENTAS);
    
    if(archivo) {
        char linea[200];
        while(archivo.getline(linea, sizeof(linea))) {
            if(strlen(linea) > 0) {
                Venta venta;
                parsearLineaVenta(linea, venta);
                ventas.push_back(venta);
            }
        }
        archivo.close();
    }
}

int obtenerCantidadVendida(int codigoProducto) {
    vector<Venta> ventas;
    leerVentas(ventas);
    
    int totalVendido = 0;
    for(const auto& venta : ventas) {
        if(venta.codigoProducto == codigoProducto) {
            totalVendido += venta.cantidad;
        }
    }
    
    return totalVendido;
}