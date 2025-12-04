// Materia: Programación I, Paralelo 4
// Autor: ……………………..
// Fecha creación: 11-11-2025
// Número de ejercicio: 1
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Estructuras de datos
struct Estudiante
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct Notas
{
    char ci[10];
    char materia[30];
    int nota;
};

// Nombres de archivos
const char* ARCHIVO_ESTUDIANTES = "ESTUDIANTES.BIN";  // Archivo binario
const char* ARCHIVO_NOTAS = "NOTAS.TXT";             // Archivo de texto

// Funciones del programa
void ingresarEstudiante();
void ingresarMateriasNotas();
void mostrarReporte();
void mostrarMenu();
bool existeEstudiante(const char* ci);
void guardarEstudianteBinario(const Estudiante& estudiante);
void guardarNotaTexto(const Notas& nota);
void leerEstudiantesBinario(vector<Estudiante>& estudiantes);
void leerNotasTexto(vector<Notas>& notas);
void parsearLineaNota(const char* linea, Notas& nota);

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ingresarEstudiante();
                break;
            case 2:
                ingresarMateriasNotas();
                break;
            case 3:
                mostrarReporte();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        
        cout << endl;
    } while(opcion != 4);
    
    return 0;
}

void mostrarMenu() {
    cout << "=================================" << endl;
    cout << "       SISTEMA DE NOTAS" << endl;
    cout << "=================================" << endl;
    cout << "1. Ingreso de datos estudiantes" << endl;
    cout << "2. Ingreso de materias y notas" << endl;
    cout << "3. Reporte de estudiantes y notas" << endl;
    cout << "4. Salir" << endl;
    cout << "=================================" << endl;
}

void ingresarEstudiante() {
    Estudiante nuevo;
    
    cin.ignore(); // Limpiar buffer
    cout << "\n--- INGRESO DE ESTUDIANTE ---" << endl;
    
    cout << "Cedula de identidad (max 9 digitos): ";
    cin.getline(nuevo.ci, 10);
    
    // Verificar si el estudiante ya existe
    if(existeEstudiante(nuevo.ci)) {
        cout << "Error: Ya existe un estudiante con esta cedula." << endl;
        return;
    }
    
    cout << "Nombres: ";
    cin.getline(nuevo.nombres, 30);
    
    cout << "Apellidos: ";
    cin.getline(nuevo.apellidos, 30);
    
    // Guardar en archivo binario
    guardarEstudianteBinario(nuevo);
    
    cout << "Estudiante registrado exitosamente!" << endl;
}

void ingresarMateriasNotas() {
    char ci[10];
    Notas nuevaNota;
    
    cin.ignore(); // Limpiar buffer
    cout << "\n--- INGRESO DE MATERIAS Y NOTAS ---" << endl;
    
    cout << "Cedula del estudiante: ";
    cin.getline(ci, 10);
    
    // Verificar si el estudiante existe
    if(!existeEstudiante(ci)) {
        cout << "Error: No existe un estudiante con esta cedula." << endl;
        cout << "Primero registre al estudiante (Opcion 1)." << endl;
        return;
    }
    
    // Copiar la CI a la estructura de nota
    strcpy(nuevaNota.ci, ci);
    
    cout << "Nombre de la materia: ";
    cin.getline(nuevaNota.materia, 30);
    
    cout << "Nota (0-100): ";
    cin >> nuevaNota.nota;
    
    // Validar nota
    while(nuevaNota.nota < 0 || nuevaNota.nota > 100) {
        cout << "Nota invalida. Ingrese un valor entre 0 y 100: ";
        cin >> nuevaNota.nota;
    }
    
    // Guardar en archivo de texto
    guardarNotaTexto(nuevaNota);
    
    cout << "Nota registrada exitosamente!" << endl;
}

void mostrarReporte() {
    // Leer todos los estudiantes del archivo binario
    vector<Estudiante> estudiantes;
    leerEstudiantesBinario(estudiantes);
    
    if(estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados." << endl;
        return;
    }
    
    // Leer todas las notas del archivo de texto
    vector<Notas> notas;
    leerNotasTexto(notas);
    
    cout << "\n===============================================================" << endl;
    cout << "                  REPORTE DE ESTUDIANTES" << endl;
    cout << "===============================================================" << endl;
    
    double promedioGeneral = 0;
    int totalEstudiantesConNotas = 0;
    
    for(const auto& estudiante : estudiantes) {
        cout << "\nCedula: " << estudiante.ci << endl;
        cout << "Estudiante: " << estudiante.nombres << " " 
             << estudiante.apellidos << endl;
        
        int totalNotas = 0;
        int sumaNotas = 0;
        
        cout << "  Materias y Notas:" << endl;
        cout << "  -----------------" << endl;
        
        // Buscar notas para este estudiante en el archivo de texto
        for(const auto& nota : notas) {
            if(strcmp(nota.ci, estudiante.ci) == 0) {
                cout << "  - " << setw(25) << left << nota.materia 
                     << ": " << setw(3) << right << nota.nota << endl;
                sumaNotas += nota.nota;
                totalNotas++;
            }
        }
        
        if(totalNotas == 0) {
            cout << "  No tiene materias registradas." << endl;
        } else {
            // Calcular promedio del estudiante
            double promedio = (double)sumaNotas / totalNotas;
            cout << "  Total materias: " << totalNotas << endl;
            cout << "  Promedio: " << fixed << setprecision(2) << promedio << endl;
            
            // Acumular para promedio general
            promedioGeneral += promedio;
            totalEstudiantesConNotas++;
        }
        
        cout << "---------------------------------------------------------------" << endl;
    }
    
    cout << "Total de estudiantes: " << estudiantes.size() << endl;
    cout << "Total de notas registradas: " << notas.size() << endl;
    
    if(totalEstudiantesConNotas > 0) {
        promedioGeneral = promedioGeneral / totalEstudiantesConNotas;
        cout << "Promedio general de estudiantes con notas: " 
             << fixed << setprecision(2) << promedioGeneral << endl;
    }
}

bool existeEstudiante(const char* ci) {
    ifstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    
    if(!archivo) {
        return false; // Si el archivo no existe, no hay estudiantes
    }
    
    Estudiante temp;
    while(archivo.read((char*)&temp, sizeof(Estudiante))) {
        if(strcmp(temp.ci, ci) == 0) {
            archivo.close();
            return true;
        }
    }
    
    archivo.close();
    return false;
}

void guardarEstudianteBinario(const Estudiante& estudiante) {
    ofstream archivo(ARCHIVO_ESTUDIANTES, ios::binary | ios::app);
    
    if(archivo) {
        archivo.write((char*)&estudiante, sizeof(Estudiante));
        archivo.close();
    } else {
        cout << "Error al guardar el estudiante en archivo binario." << endl;
    }
}

void guardarNotaTexto(const Notas& nota) {
    ofstream archivo(ARCHIVO_NOTAS, ios::app);
    
    if(archivo) {
        archivo << nota.ci << "; "
                << nota.materia << "; "
                << nota.nota << endl;
        archivo.close();
    } else {
        cout << "Error al guardar la nota en archivo de texto." << endl;
    }
}

void leerEstudiantesBinario(vector<Estudiante>& estudiantes) {
    ifstream archivo(ARCHIVO_ESTUDIANTES, ios::binary);
    
    if(archivo) {
        Estudiante temp;
        while(archivo.read((char*)&temp, sizeof(Estudiante))) {
            estudiantes.push_back(temp);
        }
        archivo.close();
    }
}

void parsearLineaNota(const char* linea, Notas& nota) {
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
        strncpy(nota.ci, token, 9);
        nota.ci[9] = '\0';
    }
    
    // Buscar segundo punto y coma (Materia)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while(end > token && *end == ' ') end--;
        *(end + 1) = '\0';
        strncpy(nota.materia, token, 29);
        nota.materia[29] = '\0';
    }
    
    // Buscar tercer punto y coma (Nota)
    token = strtok(NULL, ";");
    if(token != NULL) {
        // Eliminar espacios
        while(*token == ' ') token++;
        nota.nota = atoi(token);
    } else {
        // Si no hay más punto y coma, intentar con el resto de la línea
        token = strtok(NULL, "\n");
        if(token != NULL) {
            while(*token == ' ') token++;
            nota.nota = atoi(token);
        }
    }
}

void leerNotasTexto(vector<Notas>& notas) {
    ifstream archivo(ARCHIVO_NOTAS);
    
    if(archivo) {
        char linea[200];
        while(archivo.getline(linea, sizeof(linea))) {
            if(strlen(linea) > 0) {
                Notas nota;
                parsearLineaNota(linea, nota);
                notas.push_back(nota);
            }
        }
        archivo.close();
    }
}