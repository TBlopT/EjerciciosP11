/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2024-2025
 *
 * @author  Pablo Romero Armas alu0101743844@ull.edu.es
 * @date dic 01 2024
 * @brief 
 *
 *
 *
 * @bug There are no known bugs
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

// Función para el cifrado XOR
void cifradoXOR(const string& entrada, const string& salida, const string& password, char operacion) {
    ifstream archivo_entrada(entrada, ios::binary);
    ofstream archivo_salida(salida, ios::binary);

    if (!archivo_entrada.is_open() || !archivo_salida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        exit(1);
    }

    size_t password_len = password.size();
    size_t i = 0;
    char c;
    while (archivo_entrada.get(c)) {
        char clave = password[i % password_len]; // Selección de clave cíclica
        if (operacion == '+') {
            archivo_salida.put(c ^ clave); // Encriptar
        } else if (operacion == '-') {
            archivo_salida.put(c ^ clave); // Desencriptar (igual que en el cifrado)
        }
        i++;
    }

    archivo_entrada.close();
    archivo_salida.close();
}

// Función para el cifrado de César
void cifradoCesar(const string& entrada, const string& salida, int k, char operacion) {
    ifstream archivo_entrada(entrada);
    ofstream archivo_salida(salida);

    if (!archivo_entrada.is_open() || !archivo_salida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        exit(1);
    }

    char c;
    while (archivo_entrada.get(c)) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = (operacion == '+') ? k : -k;
            c = (c - base + shift + 26) % 26 + base; // Desplazamiento circular
        }
        archivo_salida.put(c);
    }

    archivo_entrada.close();
    archivo_salida.close();
}

// Función para mostrar la ayuda
void mostrarAyuda() {
    cout << "./cripto -- Cifrado de ficheros" << endl;
    cout << "Modo de uso: ./cripto fichero_entrada fichero_salida metodo password operacion" << endl;
    cout << "\n";
    cout << "fichero_entrada: Fichero a codificar" << endl;
    cout << "fichero_salida: Fichero codificado" << endl;
    cout << "metodo: Indica el metodo de encriptado" << endl;
    cout << "  1: Cifrado XOR" << endl;
    cout << "  2: Cifrado de Cesar" << endl;
    cout << "password: Palabra secreta en el caso de metodo 1, valor de K en el metodo 2" << endl;
    cout << "operacion: Operacion a realizar en el fichero" << endl;
    cout << "  +: Encriptar el fichero" << endl;
    cout << "  -: Desencriptar el fichero" << endl;
}

// Función principal
int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "./cripto -- Cifrado de ficheros" << endl;
        cout << "Modo de uso: ./cripto fichero_entrada fichero_salida metodo password operacion" << endl;
        cout << "Pruebe ./cripto --help para más información" << endl;
        return 0;
    }

    if (string(argv[1]) == "--help") {
        mostrarAyuda();
        return 0;
    }

    // Comprobamos que haya suficientes argumentos
    if (argc != 6) {
        cerr << "Error: Número incorrecto de argumentos." << endl;
        mostrarAyuda();
        return 1;
    }

    string fichero_entrada = argv[1];
    string fichero_salida = argv[2];
    int metodo = stoi(argv[3]);
    string password = argv[4];
    char operacion = argv[5][0];

    // Validar que la operación sea + o -
    if (operacion != '+' && operacion != '-') {
        cerr << "Error: La operación debe ser '+' o '-'." << endl;
        return 1;
    }

    // Procesar según el método seleccionado
    switch (metodo) {
        case 1: // Cifrado XOR
            cifradoXOR(fichero_entrada, fichero_salida, password, operacion);
            break;
        case 2: // Cifrado de César
            // Aseguramos que el password sea un número (para el valor de K)
            try {
                int k = stoi(password);
                cifradoCesar(fichero_entrada, fichero_salida, k, operacion);
            } catch (const invalid_argument&) {
                cerr << "Error: El valor de K debe ser un número." << endl;
                return 1;
            }
            break;
        default:
            cerr << "Error: Método de encriptado no válido. Use 1 para XOR o 2 para César." << endl;
            return 1;
    }

    cout << "Operación completada con éxito." << endl;
    return 0;
}

