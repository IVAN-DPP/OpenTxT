#include<c++/8/iostream>
#include<c++/8/string>
#include<c++/8/fstream>
#include<stdlib.h>
using namespace std;

class Acentos{
private:
  string text, textName;
public:
  /* ---- Constructors ------*/
  Acentos();
  Acentos(string);

  /* ----- Methods ----------*/

  void text_file(string);
  string load_file();
 
};

Acentos::Acentos(){}
Acentos::Acentos(string Text){text=Text;}

void Acentos::text_file(string Name){textName=Name;} //Mutator

string Acentos::load_file(){
  string var_temp; //Temporary variable

  if(text.empty()){
    fstream input_file;
    string load_text;            
    input_file.open(textName,ios::in);

    if(input_file.fail()){
      cout << "No se pudo cargar el archivo\n";
      exit(0);    
    }
    getline(input_file,load_text,';');
    var_temp=load_text;
  }
  else
    var_temp=text;

  return var_temp;
}

int main(){
  Acentos a("Holá me llamo iván");
  string texto;
  texto = a.load_file();

  string vocal("áéíóú");
  
  for(size_t i=0;i<vocal.size();i++)
    cout << vocal[i] << endl;
  
  /*Para las vocales en May y Min.
    1) substr(0,2) 
    2) substr(2,2)
    3) substr(4,2)
    4) substr(6,2)
    .
    .
    .
    n) substr(2*n,cualquier numero>1)
  */

  return 0;
}
