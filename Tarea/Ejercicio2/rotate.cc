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
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;
int main (int const argc,char* argv[]){
ifstream archivo(argv[1]);
string linea;
string palabra;
while (getline (archivo,linea)){
  istringstream flujo(linea);  
  while(flujo>>palabra){
    for(char& letra:palabra){
     if (letra=='a'){letra='e';} 
     if (letra=='e'){letra='i';}
     if (letra=='i'){letra='o';}
     if (letra=='o'){letra='u';}
     if (letra=='u'){letra='a';}
    }
  cout << palabra << " ";
  }
cout << endl;
}
archivo.close();
return 0;
}

