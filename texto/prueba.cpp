#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include "palabras.h"
using namespace std;

class Prueba{
private:
  string text,text_name;
public:
  Prueba();
  Prueba(string);

  void set_text(string);
  //void set_word(string);
  void get_text();
  vector<string> get_paragraph();
  vector< vector<string> > get_all_word_matrix();
  vector< vector<string> > get_word_matrix(vector< vector<int> > &);
  vector< vector<int> > get_frequency_matrix();
  void load_text();
};

Prueba::Prueba(){}
Prueba::Prueba(string Text_name){text_name=Text_name;}

void Prueba::load_text(){

  string var_temp; //Temporary variable

  if(text.empty()){
    fstream input_file;
    string load_text;            
    input_file.open(text_name,ios::in);

    if(input_file.fail()){
      cout << "No se pudo cargar el archivo\n";
      exit(0);    
    }
    getline(input_file,load_text,';');
    text=load_text;
  }
}

void Prueba::get_text(){cout << text << endl;}



vector<string> Prueba::get_paragraph(){
  vector<string> list_of_paragraphs;
  string paragraph;
  int temp=0;                               //Indice con el que inicia un parrafo
  for(int i=0;i<text.size();i++){

    if(text[i]=='\n' && text[i+1]=='\n')   //Por si un parrafo esta separado con doble enter
      continue;
    
    else if(text[i]=='\n'){                      //Si se cumple la condición es porque termino un parrafo
      paragraph=text.substr(temp,i);             //Guarda o asigna el parrafo en "paragraph"
      temp=i;                                    //Pone el inicio del siguiente parrafo
      list_of_paragraphs.push_back(paragraph);   //Guarda el parrafo en el vector "list_of_paragrapghs"
    }
  }
  return list_of_paragraphs;
}


vector< vector<string> > Prueba::get_word_matrix(vector< vector<int> > &frequency_matrix){
  vector<string> word_vector;
  vector< vector<string> > word_matrix;
  vector<string> final_word_vector;
  vector< vector<string> > final_word_matrix;
  string word;
  int temp=0;                                                                 //Indica el indice con el cual empieza una palabra 
  for(int j=0;j<get_paragraph().size();j++){                                  //Este primer bucle retorna la matriz de vectores fila
    for(int i=0;i<(get_paragraph()[j]).size();i++){                             //Este segundo bucle retorna un vector fila por cada parrafo

      /*-------------------------------------------- Sección de simbolos ----------------------------------------*/

      if(get_paragraph()[j][i]=='.' || get_paragraph()[j][i]==',' ||
	 get_paragraph()[j][i]==')' || get_paragraph()[j][i]=='!' ||
	 get_paragraph()[j][i]=='?'){                                           //Si una palabra termina con punto, coma, sign interrogración, etc.
	word=(get_paragraph()[j]).substr(temp,i-temp);                          //Guarda o asigna la palabra en word, empieza en temp y escoge (i-temp) elementos
	temp=i+1;                                                               //Pone en temp el inicio de la siguiente palabra
	word_vector.push_back(word);                                          //Guarda la palabra en el vector "word_vector"
      }
      else if(get_paragraph()[j][i-1]=='.' || get_paragraph()[j][i-1]==',' ||
	      get_paragraph()[j][i-1]==')' || get_paragraph()[j][i-1]=='!' ||
	      get_paragraph()[j][i-1]=='?')                                     //Para que no vuelva a guardar la palabra que acababa con punto, coma, etc.
	temp++;                                                                 //Se le suma el siguiente para que no tome la palabra desde el espacio en blanco ' '


      else if(get_paragraph()[j][i]=='(')                                       //Si una palabra empieza con parentesis
	temp=i+1;                                                             

      // El trato de las comillas es diferente debido a que no
      // hay diferencia entre la que abre y cierra
      
      else if(get_paragraph()[j][i]=='"' && get_paragraph()[j][i-1]==' ')       
	temp=i+1;
      
      else if(get_paragraph()[j][i]=='"' && get_paragraph()[j][i+1]==' '){
	word=(get_paragraph()[j]).substr(temp,i-temp);                          //Guarda o asigna la palabra en word, empieza en temp y escoge (i-temp) elementos
	temp=i+1;                                                               //Pone en temp el inicio de la siguiente palabra
	word_vector.push_back(word);
      }

      else if(get_paragraph()[j][i-1]=='"' && get_paragraph()[j][i]==' ')
	temp++;
	
      else if(get_paragraph()[j].substr(i,2)=="¡" || get_paragraph()[j].substr(i,2)=="¿") //En este caso los caracteres valen por dos
	temp=i+2;
       
      /*------------------------------- FIN Sección de simbolos -------------------------------------------*/
      
      else if(get_paragraph()[j][i]==' '){                                    //Se escoge una palabra que no termine con punto y coma
	word=(get_paragraph()[j]).substr(temp,i-temp);                        
	temp=i+1;                                                             
	word_vector.push_back(word);                                        
      }
     
      else if(get_paragraph()[j][i]=='.' && get_paragraph()[j][i+1]=='\n'){  //Si se cumple esta condición es porque llego al final del parrafo
	word=(get_paragraph()[j]).substr(temp,i-temp);
	word_vector.push_back(word);
	break;
      }
      else if(get_paragraph()[j][i]=='\n')                                    //Por si el otro parrafo comienza con un salto de lineas
	temp++;
    }
    word_matrix.push_back(word_vector);                                       //Guardamos el vector de palabras en el vector "word_matrix"
    word_vector.clear();                                                      //Limpiamos cualquier palabra del parrafo anterior
    temp=0;                                                                   //Inicializamos de cero de nuevo el indice con el que empieza la palabra
  }

  // La matriz se puede ver como si sus filas representaran los parrafos en el texto,
  // p, Ej, word_matrix[1][] representa el segundo parrafo del texto, las columnas
  // representan las palabras que tiene cada parrafo.

  
  for(int k=0;k<word_matrix.size();k++){                                     //Primer bucle para correr dendro de las filas de word_matrix
    
    final_word_vector.push_back(word_matrix[k][0]);                          //Guardamos la primera palabra para poder empezar la comparación
    for(int j=0;j<(word_matrix[k]).size();j++){                              //Segundo bucle para correr dentro de las columnas de word_matrix
      temp=0;                                                                //Esta variable realiza el conteo de las veces que se repite la palabra
      for(int i=0;i<final_word_vector.size();i++)                            //Tercer bucle para correr dentro de nuestro nuevo vector y en el que guardaremos las palabras que no se repitan
	if(final_word_vector[i]!=word_matrix[k][j]){                         //Este condicional busca si la palabra en word_matrix se repite en final_word_vector
	  temp++;                                                            
	  if(temp==final_word_vector.size())                                 //Si el condicional anterior se cumple para todas las palabras entonces la variable temp debera ser igual al tamaño del final_word_vector, ya que si no fuera igual entonces no la contaria y el tamaño de temp seria menor
	    final_word_vector.push_back(word_matrix[k][j]);                  //Guardamos la palabra que no se repite
	}
    }
    final_word_matrix.push_back(final_word_vector);                          //Guardamos el nuevo vector en la nueva matriz
    final_word_vector.clear();                                               //Limpiamos el vector y volvemos a empezar desde el primer bucle con el segundo parrafo
  }

  /*----------------------  Función de Frecuencia ----------------*/
  // Anteriormente se pasa como parametro por referencia la matriz frequency_matrix,
  // debido a que necesitamos la matriz que contiene todas las palabras (word_matrix)
  // para realizar la comparación con las palabras de (final_word_matrix).

  vector<int> frequency_vector;
  for(int k=0;k<final_word_matrix.size();k++){                   //Primer bucle para correr sobre las filas de final_word_matrix y word_matrix
    for(int j=0;j<final_word_matrix[k].size();j++){              //Segundo bucle para correr sobre las columnas de final_word_matrix
      temp=0;                                                    //Parametro para contar las veces que se repite la palabra
      for(int i=0;i<word_matrix[k].size();i++){                  //Tercer bucle para correr sobre las columnas de word_matrix
	if(final_word_matrix[k][j]==word_matrix[k][i])           //Este condicional nos permote realizar un conteo de las veces que se repite la palabra
	  temp++;
      }
      frequency_vector.push_back(temp);                          //Guardamos las veces que se repite cada palabra en el vector frequency_vector
    }
    frequency_matrix.push_back(frequency_vector);                //Guardamos el vector en la matriz frequency_matrix
    frequency_vector.clear();                                    //Limpiamos el vector para poder iniciar otra vez el bucle
  }

  
  return final_word_matrix;
}



 
int main(){

  Prueba a("prb.txt");
  a.load_text();
  //a.get_text();
  vector<vector<int>> frequency_matrix;
  vector<vector<string>> final_word_matrix = a.get_word_matrix(frequency_matrix);
  cout << a.get_paragraph()[0] << endl;
  cout << a.get_paragraph()[1] << endl;
  for(int i=0;i<frequency_matrix.size();i++){
    for(int j=0;j<frequency_matrix[i].size();j++)
      cout << frequency_matrix[i][j] << "  " << final_word_matrix[i][j]<<endl;
    cout << "\n---------------------------\n";
    }
  // for(int i=0;i<(a.get_word_list()).size();i++)
  //   cout << a.get_word_list()[i] <<endl;
  // string text_w="hoéa";
  // char textC[text_w.size()];
  // for(int i=0;i<text_w.size();i++){
  //   textC[i]=tolower(text_w[i]);
  //   cout << textC[i]<<endl;
  // }
  // text_w=textC;
  // cout << textC << endl;
  //a.get_frequency_matrix();
  return 0;
}
