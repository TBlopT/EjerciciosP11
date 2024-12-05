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
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
string nombre;
bool check(char& a){
vector <char> vocales {'A','a','E','e','I','i','O','o','U','u'};
if (find(vocales.begin(),vocales.end(),a) == vocales.end()){
return false;
}
else {
  return true;
}

}
int main (int const argc, char* argv[]) {
nombre = (argv[1]);
ifstream texto(argv[1]);
string linea;
int contador {0};
int MAX {0};
string MAX_palabra;
while (getline(texto, linea)){
  istringstream palabras(linea);
  string palabra;
 while (palabras>>palabra){
  for(char letra:palabra){
   if(check(letra)){
   contador++;
   }
  }
 if (contador>MAX){
   MAX=contador;
   MAX_palabra=palabra;
 }
 }
}
cout << "Palabra con más consonantes: " << MAX_palabra << endl;
}
