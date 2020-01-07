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



