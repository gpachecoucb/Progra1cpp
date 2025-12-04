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

// Estructura para estudiantes
struct Estudiante {
    char carnet[20];
    char nombres[50];
    char apellidos[50];
    char materia[50];
    int paralelo;
};

// Estructura para notas
struct Nota {
    char carnet[20];
    char materia[50];
    int paralelo;
    double nota1;
    double nota2;
    double nota3;
};

// Nombres de archivos
const char* ARCHIVO_ESTUDIANTES = "ESTUDIANTES.BIN";
const char* ARCHIVO_NOTAS = "NOTAS.TXT";

// Funciones del programa
void adicionarEstudiante();
void listadoEstudiantesHabilitados();
void eliminarEstudiante();
void adicionarNotasHabilitacion();
void mostrarMenu();
bool existeEstudiante(const char* carnet, const char* materia, int paralelo);
void guardarEstudiante(const Estudiante& estudiante);
void leerEstudiantes(vector<Estudiante>& estudiantes);
void guardarNotaEnTexto(const Nota& nota);
void leerNotas(vector<Nota>& notas);
void parsearLineaNota(const char* linea, Nota& nota);
double calcularNotaHabilitacion(const Nota& nota);
bool estaHabilitado(const Nota& nota);

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                adicionarEstudiante();
                break;
            case 2:
                listadoEstudiantesHabilitados();
                break;
            case 3:
                eliminarEstudiante();
                break;
            case 4:
                adicionarNotasHabilitacion();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        
        cout << endl;
    } while(opcion != 5);
    
    return 0;
}

void mostrarMenu() {
    cout << "================================" << endl;
    cout << "         NOTAS UCB" << endl;
    cout << "================================" << endl;
    cout << "1. Adicionar Estudiante" << endl;
    cout << "2. Listado de Estudiantes Habilitados" << endl;
    cout << "3. Eliminar un Estudiante" << endl;
    cout << "4. Adicionar notas habilitacion" << endl;
    cout << "5. Salir" << endl;
    cout << "================================" << endl;
}

void adicionarEstudiante() {
    Estudiante nuevo;
    
    cout << "\n--- ADICIONAR ESTUDIANTE ---" << endl;
    
    cin.ignore(); // Limpiar buffer
    cout << "Carnet de Identidad: ";
    cin.getline(nuevo.carnet, 20);
    
    cout << "Nombres: ";
    cin.getline(nuevo.nombres, 50);
    
    cout << "Apellidos: ";
    cin.getline(nuevo.apellidos, 50);
    
    cout << "Materia: ";
    cin.getline(nuevo.materia, 50);
    
    cout << "Paralelo: ";
    cin >> nuevo.paralelo;
    
    // Verificar si el estudiante ya existe en la misma materia y paralelo
    if(existeEstudiante(nuevo.carnet, nuevo.materia, nuevo.paralelo)) {
        cout << "Error: Ya existe un estudiante con este carnet en la misma materia y paralelo." << endl;
        return;
    }
    
    // Guardar en archivo binario
    guardarEstudiante(nuevo);
    
    cout << "Estudiante registrado exitosamente!" << endl;
}

void listadoEstudiantesHabilitados() {
    vector<Estudiante> estudiantes;
    vector<Nota> notas;
    
    // Leer estudiantes del archivo binario
    leerEstudiantes(estudiantes);
    
    if(estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados." << endl;
        return;
    }
    
    // Leer notas del archivo de texto
    leerNotas(notas);
    
    if(notas.empty()) {
        cout << "\nNo hay notas registradas." << endl;
        return;
    }
    
    cout << "\n==================================================================================================================" << endl;
    cout << "                            LISTADO DE ESTUDIANTES HABILITADOS" << endl;
    cout << "==================================================================================================================" << endl;
    cout << left << setw(12) << "CARNET" 
         << setw(15) << "NOMBRES" 
         << setw(15) << "APELLIDOS" 
         << setw(25) << "MATERIA" 
         << setw(10) << "PARALELO" 
         << setw(20) << "NOTA HABILITACION" 
         << setw(15) << "ESTADO" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    
    int totalEstudiantes = 0;
    double sumaNotasHabilitacion = 0;
    
    for(const auto& estudiante : estudiantes) {
        bool tieneNotas = false;
        double notaHabilitacion = 0;
        bool habilitado = false;
        
        // Buscar notas para este estudiante
        for(const auto& nota : notas) {
            if(strcmp(nota.carnet, estudiante.carnet) == 0 &&
               strcmp(nota.materia, estudiante.materia) == 0 &&
               nota.paralelo == estudiante.paralelo) {
                
                tieneNotas = true;
                notaHabilitacion = calcularNotaHabilitacion(nota);
                habilitado = estaHabilitado(nota);
                break;
            }
        }
        
        if(tieneNotas) {
            totalEstudiantes++;
            sumaNotasHabilitacion += notaHabilitacion;
            
            cout << left << setw(12) << estudiante.carnet
                 << setw(15) << estudiante.nombres
                 << setw(15) << estudiante.apellidos
                 << setw(25) << estudiante.materia
                 << setw(10) << estudiante.paralelo
                 << setw(20) << fixed << setprecision(2) << notaHabilitacion;
            
            if(habilitado) {
                cout << setw(15) << "HABILITADO" << endl;
            } else {
                cout << setw(15) << "NO HABILITADO" << endl;
            }
        }
    }
    
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    
    if(totalEstudiantes > 0) {
        double promedio = sumaNotasHabilitacion / totalEstudiantes;
        cout << "Total estudiantes con notas: " << totalEstudiantes << endl;
        cout << "Promedio de notas de habilitacion: " << fixed << setprecision(2) << promedio << endl;
    } else {
        cout << "No hay estudiantes con notas registradas." << endl;
    }
    
    cout << "==================================================================================================================" << endl;
}

void eliminarEstudiante() {
    char carnet[20];
    char materia[50];
    int paralelo;
    
    cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;
    
    cin.ignore(); // Limpiar buffer
    cout << "Carnet del estudiante: ";
    cin.getline(carnet, 20);
    
    cout << "Materia: ";
    cin.getline(materia, 50);
    
    cout << "Paralelo: ";
    cin >> paralelo;
    
    // Leer todos los estudiantes
    vector<Estudiante> estudiantes;
    leerEstudiantes(estudiantes);
    
    if(estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    
    // Buscar el estudiante a eliminar
    bool encontrado = false;
    vector<Estudiante> nuevosEstudiantes;
    
    for(const auto& estudiante : estudiantes) {
        if(strcmp(estudiante.carnet, carnet) == 0 &&
           strcmp(estudiante.materia, materia) == 0 &&
           estudiante.paralelo == paralelo) {
            
            encontrado = true;
            cout << "\nEstudiante encontrado para eliminar:" << endl;
            cout << "Nombres: " << estudiante.nombres << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            cout << "Materia: " << estudiante.materia << endl;
            cout << "Paralelo: " << estudiante.paralelo << endl;
            
            char confirmar;
            cout << "\n¿Esta seguro de eliminar este estudiante? (s/n): ";
            cin >> confirmar;
            
            if(confirmar == 's' || confirmar == 'S') {
                // No agregar este estudiante al nuevo vector (eliminarlo)
                cout << "Estudiante eliminado exitosamente!" << endl;
            } else {
                // Agregar el estudiante de nuevo (cancelar eliminación)
                nuevosEstudiantes.push_back(estudiante);
                cout << "Eliminacion cancelada." << endl;
            }
        } else {
            // Agregar los otros estudiantes
            nuevosEstudiantes.push_back(estudiante);
        }
    }
    
    if(!encontrado) {
        cout << "Estudiante no encontrado." << endl;
        return;
    }
    
    // Guardar los estudiantes restantes
    ofstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    if(archivo) {
        for(const auto& estudiante : nuevosEstudiantes) {
            archivo.write((char*)&estudiante, sizeof(Estudiante));
        }
        archivo.close();
    }
}

void adicionarNotasHabilitacion() {
    Nota nuevaNota;
    
    cout << "\n--- ADICIONAR NOTAS DE HABILITACION ---" << endl;
    
    cin.ignore(); // Limpiar buffer
    cout << "Carnet del estudiante: ";
    cin.getline(nuevaNota.carnet, 20);
    
    cout << "Materia: ";
    cin.getline(nuevaNota.materia, 50);
    
    cout << "Paralelo: ";
    cin >> nuevaNota.paralelo;
    
    // Verificar si el estudiante existe
    if(!existeEstudiante(nuevaNota.carnet, nuevaNota.materia, nuevaNota.paralelo)) {
        cout << "Error: No existe un estudiante con estos datos." << endl;
        cout << "Primero registre al estudiante (Opcion 1)." << endl;
        return;
    }
    
    cout << "Nota 1 (max 100): ";
    cin >> nuevaNota.nota1;
    
    cout << "Nota 2 (max 33.33): ";
    cin >> nuevaNota.nota2;
    
    cout << "Nota 3 (max 33.34): ";
    cin >> nuevaNota.nota3;
    
    // Validar rangos de notas
    if(nuevaNota.nota1 < 0 || nuevaNota.nota1 > 100) {
        cout << "Error: Nota 1 debe estar entre 0 y 100." << endl;
        return;
    }
    
    if(nuevaNota.nota2 < 0 || nuevaNota.nota2 > 33.33) {
        cout << "Error: Nota 2 debe estar entre 0 y 33.33." << endl;
        return;
    }
    
    if(nuevaNota.nota3 < 0 || nuevaNota.nota3 > 33.34) {
        cout << "Error: Nota 3 debe estar entre 0 y 33.34." << endl;
        return;
    }
    
    // Guardar nota en archivo de texto
    guardarNotaEnTexto(nuevaNota);
    
    double notaHabilitacion = calcularNotaHabilitacion(nuevaNota);
    bool habilitado = estaHabilitado(nuevaNota);
    
    cout << "\nNotas registradas exitosamente!" << endl;
    cout << "Nota de habilitacion: " << fixed << setprecision(2) << notaHabilitacion << endl;
    cout << "Estado: " << (habilitado ? "HABILITADO" : "NO HABILITADO") << endl;
}

bool existeEstudiante(const char* carnet, const char* materia, int paralelo) {
    ifstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    
    if(!archivo) {
        return false; // Si el archivo no existe, no hay estudiantes
    }
    
    Estudiante temp;
    while(archivo.read((char*)&temp, sizeof(Estudiante))) {
        if(strcmp(temp.carnet, carnet) == 0 &&
           strcmp(temp.materia, materia) == 0 &&
           temp.paralelo == paralelo) {
            archivo.close();
            return true;
        }
    }
    
    archivo.close();
    return false;
}

void guardarEstudiante(const Estudiante& estudiante) {
    ofstream archivo(ARCHIVO_ESTUDIANTES, ios::binary | ios::app);
    
    if(archivo) {
        archivo.write((char*)&estudiante, sizeof(Estudiante));
        archivo.close();
    } else {
        cout << "Error al guardar el estudiante." << endl;
    }
}

void leerEstudiantes(vector<Estudiante>& estudiantes) {
    ifstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    
    if(archivo) {
        Estudiante temp;
        while(archivo.read((char*)&temp, sizeof(Estudiante))) {
            estudiantes.push_back(temp);
        }
        archivo.close();
    }
}

void guardarNotaEnTexto(const Nota& nota) {
    ofstream archivo(ARCHIVO_NOTAS, ios::app);
    
    if(archivo) {
        archivo << nota.carnet << "; "
                << nota.materia << "; "
                << nota.paralelo << "; "
                << fixed << setprecision(2) << nota.nota1 << "; "
                << nota.nota2 << "; "
                << nota.nota3 << endl;
        archivo.close();
    } else {
        cout << "Error al guardar la nota." << endl;
    }
}

void parsearLineaNota(const char* linea, Nota& nota) {
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
        strncpy(nota.carnet, token, 19);
        nota.carnet[19] = '\0';
    }
    
    // Buscar segundo punto y coma (Materia)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(nota.materia, token, 49);
        nota.materia[49] = '\0';
    }
    
    // Buscar tercer punto y coma (Paralelo)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        nota.paralelo = atoi(token);
    }
    
    // Buscar cuarto punto y coma (Nota1)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        nota.nota1 = atof(token);
    }
    
    // Buscar quinto punto y coma (Nota2)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        nota.nota2 = atof(token);
    }
    
    // Buscar sexto punto y coma (Nota3)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        nota.nota3 = atof(token);
    } else {
        // Si no hay más punto y coma, intentar con el resto de la línea
        token = strtok(NULL, "\n");
        if(token != NULL) {
            while(*token == ' ') token++;
            nota.nota3 = atof(token);
        }
    }
}

void leerNotas(vector<Nota>& notas) {
    ifstream archivo(ARCHIVO_NOTAS);
    
    if(archivo) {
        char linea[200];
        while(archivo.getline(linea, sizeof(linea))) {
            if(strlen(linea) > 0) {
                Nota nota;
                parsearLineaNota(linea, nota);
                notas.push_back(nota);
            }
        }
        archivo.close();
    }
}

double calcularNotaHabilitacion(const Nota& nota) {
    // Convertir nota1 de 0-100 a 0-33.33
    double nota1Convertida = (nota.nota1 / 100.0) * 33.33;
    
    // Sumar las tres notas
    return nota1Convertida + nota.nota2 + nota.nota3;
}

bool estaHabilitado(const Nota& nota) {
    // Para estar habilitado, TODAS las notas deben ser >= 60
    
    // Nota1 está en escala 0-100, necesita ser >= 60
    if(nota.nota1 < 60) {
        return false;
    }
    
    // Convertir 60 de escala 0-100 a escala 0-33.33
    double minimoNota2y3 = (60.0 / 100.0) * 33.33;
    
    // Nota2 y Nota3 deben ser >= al equivalente de 60 en su escala
    if(nota.nota2 < minimoNota2y3 || nota.nota3 < minimoNota2y3) {
        return false;
    }
    
    return true;
}