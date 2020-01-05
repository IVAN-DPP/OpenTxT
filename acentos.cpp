#include<c++/8/iostream>
#include<c++/8/string>
#include<c++/8/fstream>
#include<stdlib.h>
using namespace std;

class Acentos{
private:
  string text, textName;
  static string vocal;
public:
  /* ---- Constructors ------*/
  Acentos();
  Acentos(string);

  /* ----- Methods ----------*/

  //Load file
  
  void text_file(string);  //Recibe el nombre del archivo
  string load_file();      //Carga el archivo
  
  //Find intonation vocal

  void find_pos(string);   //Busca las posiciones del parametro string
};

string Acentos::vocal="áéíóú";

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

void Acentos::find_pos(string voc){
  /* El for nos permite realizar todo el recorrido en el texto
     La primera linea despues del for nos permite encontrar la vocal en la cual estamos interesados por medio del metodo "find" de string, los argumentos vocal.substr() identifica el tipo de vocal con acento en la variable static vocal.
     El primer if restringe la busqueda si la variable posicion POS llega a ser menor que 0, ya que estos valores no nos interesan
     El segundo if imprime en pantalla solo una vez la posición en la que se encuentra la vocal en el texto.
  */
  int POS=0,TEMP=0;
  int k;              //k define la posición de en la variable satatic "vocal"
  if(voc=="á")
    k=0;
  else if(voc=="é")
    k=2;
  else if(voc=="í")
    k=4;
  else if(voc=="ó")
    k=6;
  else if(voc=="ú")
    k=8;
  
  for(size_t i=0;i<load_file().size();i++){
    POS=load_file().find(vocal.substr(k,2),i);
       if(POS<0){break;}
       if(TEMP!=POS)
	 cout << POS << endl;
       TEMP=POS;

  }

}

int main(){
  Acentos a("Lá ré Putá que te pário");
  string texto;
  texto = a.load_file();
  a.find_pos("é");
  string vocal("áéíóú");
  int conteo,h,j,k=0,TEMP=0;
  conteo=0;
     h=0;
     j=0;
     for(int i=0;i<texto.size();i++){ //segundo for
       if(j!=h){
         conteo++;
         j=h;
       }
      
     }
  
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
