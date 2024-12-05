/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2024-2025
 *
 * @author  Pablo Romero Armas alu0101743844@ull.edu.es
 * @date dic 02 2024
 * @brief 
 *
 *
 *
 * @bug There are no known bugs
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int main (int const argc, char* argv[]) {

ifstream archivo(argv[1]);
ofstream archivo_salida(argv[2]);
string linea;
string palabra;
string palabra_tocha;
int contador_tocho{0};
int contador{0};
int contador_caca{0};
int contador_anterior{0};
string palabra_caca;
while (getline (archivo,linea)){
  istringstream flujo(linea);
  while (flujo>>palabra){
    for(char letra:palabra){
    contador++;
    }
  if (contador>contador_tocho){
  contador_tocho=contador;
  palabra_tocha=palabra;
  }
  if (contador<contador_caca){
  palabra_caca=palabra;
  contador_caca=contador;
  }
  }
  }
 archivo_salida << palabra_tocha << "-" << palabra_caca;
}

