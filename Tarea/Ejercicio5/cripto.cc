/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2024-2025
 *
 * @author  Pablo Romero Armas alu0101743844@ull.edu.es
 * @date dic 05 2024
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
#include <stdexcept>
#include <sstream>

using namespace std;

void xorEncryptDecrypt(string& content, const string& password) {
    size_t passwordLength = password.length();
    for (size_t i = 0; i < content.size(); i++) {
        content[i] ^= password[i % passwordLength];
    }
}

void caesarEncryptDecrypt(string& content, int key) {
    for (size_t i = 0; i < content.size(); i++) {
        if (isalpha(content[i])) {
            char offset = islower(content[i]) ? 'a' : 'A';
            content[i] = (content[i] - offset + key + 26) % 26 + offset;
        }
    }
}

void processFile(const string& inputFile, const string& outputFile, int method, const string& password, char operation, int key) {
    ifstream infile(inputFile);
    if (!infile.is_open()) {
        cerr << "Error: No se pudo abrir el fichero de entrada." << endl;
        exit(1);
    }

    stringstream buffer;
    buffer << infile.rdbuf();
    string content = buffer.str();
    infile.close();

    if (method == 1) {
        if (operation == '+') {
            xorEncryptDecrypt(content, password);
        } else if (operation == '-') {
            xorEncryptDecrypt(content, password);
        } else {
            cerr << "Operación no válida para XOR." << endl;
            exit(1);
        }
    } else if (method == 2) {
        if (operation == '+') {
            caesarEncryptDecrypt(content, key);
        } else if (operation == '-') {
            caesarEncryptDecrypt(content, -key);
        } else {
            cerr << "Operación no válida para César." << endl;
            exit(1);
        }
    } else {
        cerr << "Método no válido." << endl;
        exit(1);
    }

    ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        cerr << "Error: No se pudo abrir el fichero de salida." << endl;
        exit(1);
    }
    outfile << content;
    outfile.close();
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "./cripto -- Cifrado de ficheros" << endl;
        cout << "Modo de uso: ./cripto fichero_entrada fichero_salida metodo password operacion" << endl;
        cout << "Pruebe ./cripto --help para más información" << endl;
        return 0;
    }

    if (argc == 2 && string(argv[1]) == "--help") {
        cout << "./cripto -- Cifrado de ficheros" << endl;
        cout << "Modo de uso: ./cripto fichero_entrada fichero_salida metodo password operacion" << endl;
        cout << "fichero_entrada: Fichero a codificar" << endl;
        cout << "fichero_salida:  Fichero codificado" << endl;
        cout << "metodo:          Indica el metodo de encriptado" << endl;
        cout << "                 1: Cifrado xor" << endl;
        cout << "                 2: Cifrado de Cesar" << endl;
        cout << "password:        Palabra secreta en el caso de metodo 1, Valor de K en el metodo 2" << endl;
        cout << "operacion:       Operacion a realizar en el fichero" << endl;
        cout << "                 +: encriptar el fichero" << endl;
        cout << "                 -: desencriptar el fichero" << endl;
        return 0;
    }

    if (argc != 6) {
        cerr << "Número incorrecto de parámetros." << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];
    int method = stoi(argv[3]);
    string password = argv[4];
    char operation = argv[5][0];

    int key = 0;
    if (method == 2) {
        key = stoi(password);
    }

    processFile(inputFile, outputFile, method, password, operation, key);
    return 0;
}

