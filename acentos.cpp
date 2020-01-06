/***********************************************

                IVAN DARIO PIERNAGORDA PEÑA

               GRUPO DE FÍSICA E INFORÁTICA
                          FISINFOR

***********************************************/
#include<c++/8/iostream>
#include<c++/8/string>
#include<c++/8/fstream>
#include<c++/8/vector>
#include<c++/8/cctype>
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
  vector <size_t> get_pos_x_v(string,string *); //Da la posición de una vocal
  string get_text_w(); //Da el texto sin tildes
  string get_text_m(string *); //Da el texto en miniscula
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

vector<size_t> Acentos::get_pos_x_v(string voc,string *new_text){

  /*Este metodo es igual al anterior, lo que cambia es que devuelve un vector de posición para una sola letra
  1) El primer parametro es una vocal con tilde
  2) El segundo parametro es un texto, para el caso tratado podria ser el metodo load_file() el cual devuelve un string*/

  vector<size_t> POS_TEMP;   //Vector que contendra la posición de la vocal escogida en el parametro "voc"
  int POS=0,TEMP=0,conteo=0;
  for(size_t i=0;i<(*new_text).size();i++){
    POS=(*new_text).find(voc,i);
    if(POS<0){break;}
    if(TEMP!=POS){
      POS_TEMP.push_back(0);
      POS_TEMP[conteo]=POS;
      conteo++;
    }
    TEMP=POS;   
  }
  return POS_TEMP;  
}

  /*Existen varios problemas al cambiar la letra y son los siguientes
   1) Si en el segundo for se empezara desde la primera posición del vector pos_v entonces el segundo elemento de este vector ya no corresponderia a la vocal buscada, esto debido a que se corren las casillas
  ANTES DE SER BORRADA á
  Holá qá                 Cadena de caracteres
  ---- --                 CASILLAS
  012(3,4)56(7,8)         Vector posición
  DESPUES DE BORRADA
  Hol qá
  --- --
  01234(5,6)
  Como se puede ver la segunda á cambia de posición por lo que en la segunda iteración del bucle este borrara el elemento inicial (7,8) y no el (5,6), para solucionar esto el bucle se hace desde el ultimo elemento hasta el primero
  2) Igual que en el caso anterio se observa el mismo problema en el cual se corren las casillas para las demas letras, por lo que en el metodo get_pos_x_v admite dos parametros el primero la vocal a buscar y el segundo el texto en el cual se va a buscar la vocal, es este caso la busqueda de la letra siguiente por ejemplo de á a é no se realiza sobre el texto original, sino sobre el texto nuevo, en el cual ya se borraro la vocal á */

string Acentos::get_text_w(){

  string vocal_w("aeiou");
  string new_text=load_file(); //Se inicializa el texto en el cual se va a buscar la vocal con tilde
  vector<size_t> pos_v; //Este guardara las posiciones por cada vocal
  
  for(size_t i=0;i<=8;i+=2){
    pos_v=get_pos_x_v(vocal.substr(i,2),&new_text); 
    
    for(size_t j=pos_v.size();j>0;j--){
      new_text.replace(pos_v[j-1],2,vocal_w.substr(i/2,1));
    }
    pos_v.resize(0);
  }
  return new_text;
}

/* Este metodo convierte las mayusculas a minusculas pasando el texto original a una cadena char para utilizar la función tolower y luego pasarla a una cadena string */
string Acentos::get_text_m(string *text_w){

  char textC[(*text_w).size()];
  for(size_t i=0;i<(*text_w).size();i++)
    textC[i]=tolower((*text_w).at(i));

  (*text_w)=textC;

  return *text_w;

}

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
