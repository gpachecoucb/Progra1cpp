// Materia: Programación I, Paralelo 4
// Autor: Gabriel Alejandro Pacheco Quispe .
// Fecha creación: 11-11-2025
// Número de ejercicio: 3
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Estructura para pizzas
struct Pizza {
    int codigo;
    char nombre[50];
    char tipo[20];       // TRADICIONAL o ESPECIAL
    char tamano[20];     // XS, MEDIANA, GRANDE, FAMILIAR, INTERMINABLE
    double precio;
};

// Estructura para ventas
struct Venta {
    char carnet[20];
    int codigoPizza;
    char tamano[20];
    int cantidad;
};

// Nombres de archivos
const char* ARCHIVO_PIZZAS = "PRODUCTO.BIN";
const char* ARCHIVO_VENTAS = "VENTAS.TXT";

// Funciones del programa
void adicionarPizza();
void listadoPizzas();
void modificarPrecio();
void eliminarPizza();
void adicionarVenta();
void mostrarMenu();
bool existePizza(int codigo);
void guardarPizza(const Pizza& pizza);
void leerPizzas(vector<Pizza>& pizzas);
void guardarVentaEnTexto(const Venta& venta);
void leerVentas(vector<Venta>& ventas);
int obtenerCantidadVendida(int codigoPizza, const char* tamano);
void parsearLineaVenta(const char* linea, Venta& venta);
double calcularPrecioBase(const char* tamano);
double aplicarTipo(double precioBase, const char* tipo);
void mostrarTamano();

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                adicionarPizza();
                break;
            case 2:
                listadoPizzas();
                break;
            case 3:
                modificarPrecio();
                break;
            case 4:
                eliminarPizza();
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
    cout << "================================" << endl;
    cout << "      PIZZERIA ELI'S" << endl;
    cout << "================================" << endl;
    cout << "1. Adicionar Pizza" << endl;
    cout << "2. Listado de Pizzas" << endl;
    cout << "3. Modificar precio de la Pizza" << endl;
    cout << "4. Eliminar una Pizza" << endl;
    cout << "5. Adicionar Venta de Pizzas" << endl;
    cout << "6. Salir" << endl;
    cout << "================================" << endl;
}

void adicionarPizza() {
    Pizza nueva;
    
    cout << "\n--- ADICIONAR PIZZA ---" << endl;
    
    cout << "Codigo de la pizza: ";
    cin >> nueva.codigo;
    
    // Verificar si la pizza ya existe
    if(existePizza(nueva.codigo)) {
        cout << "Error: Ya existe una pizza con este codigo." << endl;
        return;
    }
    
    cin.ignore(); // Limpiar buffer
    cout << "Nombre de la pizza: ";
    cin.getline(nueva.nombre, 50);
    
    // Seleccionar tipo
    int tipoOpcion;
    cout << "Tipo de pizza:" << endl;
    cout << "1. TRADICIONAL" << endl;
    cout << "2. ESPECIAL" << endl;
    cout << "Seleccione (1 o 2): ";
    cin >> tipoOpcion;
    
    if(tipoOpcion == 1) {
        strcpy(nueva.tipo, "TRADICIONAL");
    } else if(tipoOpcion == 2) {
        strcpy(nueva.tipo, "ESPECIAL");
    } else {
        cout << "Opcion invalida. Se asignara TRADICIONAL por defecto." << endl;
        strcpy(nueva.tipo, "TRADICIONAL");
    }
    
    // Seleccionar tamaño
    mostrarTamano();
    int tamanoOpcion;
    cout << "Seleccione el tamaño (1-5): ";
    cin >> tamanoOpcion;
    
    switch(tamanoOpcion) {
        case 1: strcpy(nueva.tamano, "XS"); break;
        case 2: strcpy(nueva.tamano, "MEDIANA"); break;
        case 3: strcpy(nueva.tamano, "GRANDE"); break;
        case 4: strcpy(nueva.tamano, "FAMILIAR"); break;
        case 5: strcpy(nueva.tamano, "INTERMINABLE"); break;
        default: 
            cout << "Opcion invalida. Se asignara MEDIANA por defecto." << endl;
            strcpy(nueva.tamano, "MEDIANA");
    }
    
    // Calcular precio base según tamaño
    double precioBase = calcularPrecioBase(nueva.tamano);
    
    // Aplicar tipo (ESPECIAL tiene 10% adicional)
    nueva.precio = aplicarTipo(precioBase, nueva.tipo);
    
    // Guardar en archivo binario
    guardarPizza(nueva);
    
    cout << "\nPizza registrada exitosamente!" << endl;
    cout << "Precio calculado: " << fixed << setprecision(2) << nueva.precio << " Bs." << endl;
}

void listadoPizzas() {
    vector<Pizza> pizzas;
    vector<Venta> ventas;
    
    // Leer pizzas del archivo binario
    leerPizzas(pizzas);
    
    if(pizzas.empty()) {
        cout << "\nNo hay pizzas registradas." << endl;
        return;
    }
    
    // Leer ventas del archivo de texto
    leerVentas(ventas);
    
    cout << "\n========================================================================================================" << endl;
    cout << "                                    LISTADO DE PIZZAS" << endl;
    cout << "========================================================================================================" << endl;
    cout << left << setw(8) << "CODIGO" 
         << setw(20) << "NOMBRE" 
         << setw(15) << "TIPO" 
         << setw(15) << "TAMAÑO" 
         << setw(10) << "PRECIO" 
         << setw(10) << "CANTIDAD" 
         << setw(10) << "TOTAL" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    
    double totalGeneral = 0;
    
    for(const auto& pizza : pizzas) {
        int cantidadVendida = obtenerCantidadVendida(pizza.codigo, pizza.tamano);
        double totalVendido = cantidadVendida * pizza.precio;
        totalGeneral += totalVendido;
        
        cout << left << setw(8) << pizza.codigo
             << setw(20) << pizza.nombre
             << setw(15) << pizza.tipo
             << setw(15) << pizza.tamano
             << setw(10) << fixed << setprecision(2) << pizza.precio
             << setw(10) << cantidadVendida
             << setw(10) << fixed << setprecision(2) << totalVendido << endl;
    }
    
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "TOTAL GENERAL DE VENTAS: " << fixed << setprecision(2) << totalGeneral << " Bs." << endl;
    cout << "========================================================================================================" << endl;
}

void modificarPrecio() {
    int codigo;
    cout << "\n--- MODIFICAR PRECIO DE PIZZA ---" << endl;
    cout << "Ingrese el codigo de la pizza: ";
    cin >> codigo;
    
    // Leer todas las pizzas
    vector<Pizza> pizzas;
    leerPizzas(pizzas);
    
    bool encontrada = false;
    for(auto& pizza : pizzas) {
        if(pizza.codigo == codigo) {
            encontrada = true;
            
            cout << "\nPizza encontrada:" << endl;
            cout << "Nombre: " << pizza.nombre << endl;
            cout << "Tipo: " << pizza.tipo << endl;
            cout << "Tamaño: " << pizza.tamano << endl;
            cout << "Precio actual: " << fixed << setprecision(2) << pizza.precio << " Bs." << endl;
            
            cout << "\nIngrese el nuevo precio base para tamaño " << pizza.tamano << ": ";
            double nuevoPrecioBase;
            cin >> nuevoPrecioBase;
            
            // Recalcular precio según tipo
            pizza.precio = aplicarTipo(nuevoPrecioBase, pizza.tipo);
            
            cout << "Nuevo precio calculado: " << fixed << setprecision(2) << pizza.precio << " Bs." << endl;
            break;
        }
    }
    
    if(!encontrada) {
        cout << "Pizza con codigo " << codigo << " no encontrada." << endl;
        return;
    }
    
    // Guardar todas las pizzas de nuevo (sobreescribir archivo)
    ofstream archivo(ARCHIVO_PIZZAS, ios::binary);
    if(archivo) {
        for(const auto& pizza : pizzas) {
            archivo.write((char*)&pizza, sizeof(Pizza));
        }
        archivo.close();
        cout << "Precio modificado exitosamente!" << endl;
    } else {
        cout << "Error al guardar los cambios." << endl;
    }
}

void eliminarPizza() {
    int codigo;
    cout << "\n--- ELIMINAR PIZZA ---" << endl;
    cout << "Ingrese el codigo de la pizza a eliminar: ";
    cin >> codigo;
    
    // Leer todas las pizzas
    vector<Pizza> pizzas;
    leerPizzas(pizzas);
    
    if(pizzas.empty()) {
        cout << "No hay pizzas registradas." << endl;
        return;
    }
    
    // Buscar la pizza a eliminar
    bool encontrada = false;
    vector<Pizza> nuevasPizzas;
    
    for(const auto& pizza : pizzas) {
        if(pizza.codigo == codigo) {
            encontrada = true;
            cout << "\nPizza encontrada para eliminar:" << endl;
            cout << "Nombre: " << pizza.nombre << endl;
            cout << "Tipo: " << pizza.tipo << endl;
            cout << "Tamaño: " << pizza.tamano << endl;
            cout << "Precio: " << fixed << setprecision(2) << pizza.precio << " Bs." << endl;
            
            char confirmar;
            cout << "\n¿Esta seguro de eliminar esta pizza? (s/n): ";
            cin >> confirmar;
            
            if(confirmar == 's' || confirmar == 'S') {
                // No agregar esta pizza al nuevo vector (eliminarla)
                cout << "Pizza eliminada exitosamente!" << endl;
            } else {
                // Agregar la pizza de nuevo (cancelar eliminación)
                nuevasPizzas.push_back(pizza);
                cout << "Eliminacion cancelada." << endl;
            }
        } else {
            // Agregar las otras pizzas
            nuevasPizzas.push_back(pizza);
        }
    }
    
    if(!encontrada) {
        cout << "Pizza con codigo " << codigo << " no encontrada." << endl;
        return;
    }
    
    // Guardar las pizzas restantes
    ofstream archivo(ARCHIVO_PIZZAS, ios::binary);
    if(archivo) {
        for(const auto& pizza : nuevasPizzas) {
            archivo.write((char*)&pizza, sizeof(Pizza));
        }
        archivo.close();
    }
}

void adicionarVenta() {
    Venta nuevaVenta;
    int codigoPizza;
    
    cout << "\n--- ADICIONAR VENTA ---" << endl;
    
    cin.ignore(); // Limpiar buffer
    cout << "Carnet del cliente: ";
    cin.getline(nuevaVenta.carnet, 20);
    
    cout << "Codigo de la pizza: ";
    cin >> codigoPizza;
    
    // Verificar si la pizza existe
    if(!existePizza(codigoPizza)) {
        cout << "Error: No existe una pizza con este codigo." << endl;
        return;
    }
    
    // Buscar la pizza para obtener su tamaño
    vector<Pizza> pizzas;
    leerPizzas(pizzas);
    Pizza pizzaVendida;
    bool pizzaEncontrada = false;
    
    for(const auto& pizza : pizzas) {
        if(pizza.codigo == codigoPizza) {
            pizzaVendida = pizza;
            pizzaEncontrada = true;
            break;
        }
    }
    
    if(!pizzaEncontrada) {
        cout << "Error al buscar la pizza." << endl;
        return;
    }
    
    // Mostrar tamaño de la pizza
    cout << "Tamaño de la pizza (" << pizzaVendida.tamano << "): ";
    cin.ignore();
    cin.getline(nuevaVenta.tamano, 20);
    
    // Verificar que el tamaño coincida
    if(strcmp(nuevaVenta.tamano, pizzaVendida.tamano) != 0) {
        cout << "Advertencia: El tamaño ingresado no coincide con el tamaño registrado de la pizza." << endl;
        cout << "Tamaño registrado: " << pizzaVendida.tamano << endl;
        
        char continuar;
        cout << "¿Desea continuar? (s/n): ";
        cin >> continuar;
        
        if(continuar != 's' && continuar != 'S') {
            return;
        }
    }
    
    nuevaVenta.codigoPizza = codigoPizza;
    
    cout << "Cantidad de pizzas vendidas: ";
    cin >> nuevaVenta.cantidad;
    
    // Guardar venta en archivo de texto
    guardarVentaEnTexto(nuevaVenta);
    
    double totalVenta = nuevaVenta.cantidad * pizzaVendida.precio;
    cout << "\nVenta registrada exitosamente!" << endl;
    cout << "Total de la venta: " << fixed << setprecision(2) << totalVenta << " Bs." << endl;
}

bool existePizza(int codigo) {
    ifstream archivo(ARCHIVO_PIZZAS, ios::binary);
    
    if(!archivo) {
        return false; // Si el archivo no existe, no hay pizzas
    }
    
    Pizza temp;
    while(archivo.read((char*)&temp, sizeof(Pizza))) {
        if(temp.codigo == codigo) {
            archivo.close();
            return true;
        }
    }
    
    archivo.close();
    return false;
}

void guardarPizza(const Pizza& pizza) {
    ofstream archivo(ARCHIVO_PIZZAS, ios::binary | ios::app);
    
    if(archivo) {
        archivo.write((char*)&pizza, sizeof(Pizza));
        archivo.close();
    } else {
        cout << "Error al guardar la pizza." << endl;
    }
}

void leerPizzas(vector<Pizza>& pizzas) {
    ifstream archivo(ARCHIVO_PIZZAS, ios::binary);
    
    if(archivo) {
        Pizza temp;
        while(archivo.read((char*)&temp, sizeof(Pizza))) {
            pizzas.push_back(temp);
        }
        archivo.close();
    }
}

void guardarVentaEnTexto(const Venta& venta) {
    ofstream archivo(ARCHIVO_VENTAS, ios::app);
    
    if(archivo) {
        archivo << venta.carnet << ";" 
                << venta.codigoPizza << ";" 
                << venta.tamano << ";" 
                << venta.cantidad << endl;
        archivo.close();
    } else {
        cout << "Error al guardar la venta." << endl;
    }
}

void parsearLineaVenta(const char* linea, Venta& venta) {
    char tempLinea[200];
    strcpy(tempLinea, linea);
    
    // Buscar primer punto y coma (Carnet)
    char* token = strtok(tempLinea, ";");
    if(token != NULL) {
        // Eliminar espacios al inicio y final del token
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(venta.carnet, token, 19);
        venta.carnet[19] = '\0';
    }
    
    // Buscar segundo punto y coma (Código Pizza)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        venta.codigoPizza = atoi(token);
    }
    
    // Buscar tercer punto y coma (Tamaño)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(venta.tamano, token, 19);
        venta.tamano[19] = '\0';
    }
    
    // Buscar cuarto punto y coma (Cantidad)
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

int obtenerCantidadVendida(int codigoPizza, const char* tamano) {
    vector<Venta> ventas;
    leerVentas(ventas);
    
    int totalVendido = 0;
    for(const auto& venta : ventas) {
        if(venta.codigoPizza == codigoPizza && 
           strcmp(venta.tamano, tamano) == 0) {
            totalVendido += venta.cantidad;
        }
    }
    
    return totalVendido;
}

double calcularPrecioBase(const char* tamano) {
    double precioBase = 0;
    
    if(strcmp(tamano, "XS") == 0) {
        precioBase = 50.0;  // Precio base para XS
    } else if(strcmp(tamano, "MEDIANA") == 0) {
        precioBase = 80.0;  // Precio base para MEDIANA
    } else if(strcmp(tamano, "GRANDE") == 0) {
        precioBase = 100.0; // Precio base para GRANDE
    } else if(strcmp(tamano, "FAMILIAR") == 0) {
        precioBase = 120.0; // Precio base para FAMILIAR
    } else if(strcmp(tamano, "INTERMINABLE") == 0) {
        precioBase = 150.0; // Precio base para INTERMINABLE
    }
    
    return precioBase;
}

double aplicarTipo(double precioBase, const char* tipo) {
    double precioFinal = precioBase;
    
    if(strcmp(tipo, "ESPECIAL") == 0) {
        precioFinal = precioBase * 1.10; // 10% adicional
    }
    
    return precioFinal;
}

void mostrarTamano() {
    cout << "\nTamaños de pizza disponibles:" << endl;
    cout << "1. XS" << endl;
    cout << "2. MEDIANA" << endl;
    cout << "3. GRANDE" << endl;
    cout << "4. FAMILIAR" << endl;
    cout << "5. INTERMINABLE" << endl;
}