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
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Por favor, proporciona el archivo como parámetro." << endl;
        return 1;
    }

    ifstream archivo(argv[1]);  
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string linea;
    string palabra;

    ofstream archivos[26]; 

    for (int i = 0; i < 26; ++i) {
        string nombre_archivo = string(1, 'A' + i) + ".txt";  
        archivos[i].open(nombre_archivo);
        if (!archivos[i].is_open()) {
            cerr << "No se pudo abrir el archivo " << nombre_archivo << endl;
            return 1;
        }
    }

    while (getline(archivo, linea)) {
        istringstream flujo(linea);  

        while (flujo >> palabra) {
            char primera_letra = toupper(palabra[0]);
            if (isalpha(primera_letra)) {
                archivos[primera_letra - 'A'] << palabra << endl;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        archivos[i].close();
    }

    archivo.close();  
    return 0;
}

