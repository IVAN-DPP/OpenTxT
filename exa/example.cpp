#include "/......./texto/acentos.cpp" 
#include <iostream>

using namespace std;

int main(){
  Acentos a("Lá ré Putá que te pário");
  //Acentos a;
  //a.text_file("prueba.txt");
  string text;
  text = a.load_file();
  string new_text = a.get_text_w();
  
  cout << text << endl << "--------\n" << new_text << endl;

  a.get_text_m(&new_text);

  cout << "\n------------------\n" << new_text << endl; 
  
  

  return 0;
}
