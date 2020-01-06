/***********************************************

                IVAN DARIO PIERNAGORDA PEÑA

               GRUPO DE FÍSICA E INFORÁTICA
                          FISINFOR

***********************************************/
#include<c++/8/iostream>
#include<c++/8/string>
#include<c++/8/fstream>
#include<c++/8/vector>
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

  //Get

  size_t get_number(string); //Da el número de veces que esta una vocal con tilde presente en un texto

  vector< vector<size_t> > get_pos(); //Da la posición en un vector

  string get_text_w(); //Da el texto sin tildes
};

string Acentos::vocal="áéíóú";  //Variable global dentro de la clase Acentos

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
  
  for(size_t i=0;i<load_file().size();i++){
    POS=load_file().find(vocal.substr(k,2),i);
       if(POS<0){break;}
       if(TEMP!=POS)
	 cout << POS << endl;
       TEMP=POS;

  }

}

size_t Acentos::get_number(string voc){

  int POS=0,TEMP=0,conteo=0;
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
	 conteo++;
       TEMP=POS; 
  }
  return conteo;
}
/* Este metodo devuelve un vector de vectores, cada fila representa la posición de una vocal*/
vector< vector<size_t> > Acentos::get_pos(){
  vector< vector<size_t> > pos(5);
  vector<size_t> POS_TEMP;   //Vector por cada vocal
  string voc;
  int POS=0,TEMP=0,conteo=0;
  int k;              //k define la posición de en la variable satatic "vocal"
  for(size_t k=0;k<=8;k+=2){
     
    for(size_t i=0;i<load_file().size();i++){
      POS=load_file().find(vocal.substr(k,2),i);
      if(POS<0){break;}
      if(TEMP!=POS){
	POS_TEMP.push_back(0);
	POS_TEMP[conteo]=POS;
	conteo++;
      }
      TEMP=POS;   
    }
    pos[k/2]=POS_TEMP; //Se divide entre 2 porque el for se cuenta de 2 en 2.
    
    POS_TEMP.resize(0); //Se redefine los elementos del vector (cero elementos) para que POS_TEMP inicie como un núevo vector
    conteo=0;  //conteo se define como 0 para que vuelva a realizar el barrido del vector POS_TEMP en cero y no desde su ultimo valor guardado
  }
  return pos;

}




int main(){
  //Acentos a("Lá ré Putá que te pário");
  Acentos a;
  a.text_file("prueba.txt");
  string texto;
  texto = a.load_file();
  a.find_pos("á");
  cout << a.get_number("á") << endl;;
  vector< vector<size_t> > s = a.get_pos();
  /*
  for(int i=0;i<s.size();i++){
    for(int j=0;j<s[i].size();j++)
      cout << s[i][j] << endl;
    cout << "-------------------\n";
    }*/
  

  
  
  //vector<size_t> s=a.get_pos("á");

  
  
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
