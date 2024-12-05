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
string palabra_inversa;
while (getline (archivo,linea)){
  istringstream flujo(linea);
  while (flujo>>palabra){
  palabra_inversa=palabra;
  reverse(palabra_inversa.begin(),palabra_inversa.end());
  archivo_salida<<palabra_inversa<<" ";
  }
  archivo_salida << '\n'; 
}
}
