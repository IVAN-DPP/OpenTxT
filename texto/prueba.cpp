#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Prueba{
private:
  string text,text_name;
public:
  Prueba();
  Prueba(string);

  void set_text(string);
  void set_word(string);
  void get_text();
  vector<string> get_paragraph();
  vector< vector<string> > get_word_matrix();
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
    else if(text[i]==';')                        //Si sen encuentra con ; es porque el texto ya termino
      break;
    
  }
  return list_of_paragraphs;
}

vector< vector<string> > Prueba::get_word_matrix(){
  vector<string> list_of_words;
  vector< vector<string> > matrix_of_words;
  string word;
  int temp=0;                                                                 //Indica el indice con el cual empieza una palabra 
  for(int j=0;j<get_paragraph().size();j++){                                  //Este primer bucle retorna la matriz de vectores fila
    for(int i=0;i<(get_paragraph()[j]).size();i++){                           //Este segundo bucle retorna un vector fila por cada parrafo
      if(get_paragraph()[j][i]==' '){                                         //Se escoge una palabra
	word=(get_paragraph()[j]).substr(temp,i-temp);                        //Guarda o asigna la palabra en word, empieza en temp y escoge (i-temp) elementos
	temp=i+1;                                                             //Pone el inicio de la siguiente palabra
	list_of_words.push_back(word);                                        //Guarda la palabra en el vector "list_of_words"
      }

      else if(get_paragraph()[j][i]=='.' || get_paragraph()[j][i]==','){      //Si termina una palabra termina en punto o coma
	word=(get_paragraph()[j]).substr(temp,i-temp);                       
	temp=i+1;                                                             
	list_of_words.push_back(word);
      }
      else if(get_paragraph()[j][i-1]=='.' || get_paragraph()[j][i-1]==',')  //Para que no vuelva a guardar la palabra que acababa con punto o coma
	continue;
      
      else if(get_paragraph()[j][i]=='.' && get_paragraph()[j][i+1]=='\n'){  //Si se cumple esta condición es porque llego al final del parrafo
	word=(get_paragraph()[j]).substr(temp,i-temp);
	list_of_words.push_back(word);
	break;
      }
      else if(get_paragraph()[j][i]=='\n')                                    //Por si el otro parrafo comienza con un salto de lineas
	continue;
    }
    matrix_of_words.push_back(list_of_words);                                 //Guardamos el vector de palabras en el vector "matrix_of_words"
    list_of_words.clear();                                                    //Limpiamos cualquier palabra del parrafo anterior
    temp=0;                                                                   //Inicializamos de cero de nuevo el indice con el que empieza la palabra
  }

  // La matriz se puede ver como si sus filas representaran los parrafos en el texto,
  // p, Ej, matrix_of_word[1][] representa el segundo parrafo del texto, las columnas
  // representan las palabras que tiene cada parrafo.

  
    
  for(int j=0;j<matrix_of_words.size();j++){
      for(int i=0;i<matrix_of_words[j].size();i++)
        cout << matrix_of_words[j][i] << endl;
      cout << "\n-----------------------\n";
  }
  return matrix_of_words;
}

 
int main(){

  Prueba a("prb.txt");
  a.load_text();
  //a.get_text();
  a.get_word_matrix();
  cout << a.get_paragraph()[1] << endl;;
  // for(int i=0;i<(a.get_word_list()).size();i++)
  //   cout << a.get_word_list()[i] <<endl;
  
  return 0;
}
