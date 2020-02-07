#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include <iomanip>

using namespace std;

namespace OpenTxT{
  
  class Datos{
  private:
    string text,text_name;
    vector<string> names;
    vector< vector<int> > frequency_matrix0;
    vector< vector<int> > frequency_matrix1;
  public:
    Datos();
    Datos(string);
  
    void set_text(string);
    void set_text_name(string);      
    void get_text();
    vector<string> get_paragraph();
    vector<string> get_names();
    vector< vector<string> > get_word_matrix0();
    vector< vector<int> > get_frequency_matrix0();
    vector<string> get_word_vector1();
    vector< vector<int> > get_frequency_matrix1();
    void save_file1(string);
    void load_text();
  };
  
  Datos::Datos(){}
  Datos::Datos(string Text_name){text_name=Text_name;}
  
  void Datos::set_text_name(string Text_name){text_name=Text_name;}
  void Datos::load_text(){
    
    string var_temp; //Temporary variable
    vector<int> pos;
    
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
    
    /*---- LISTA DE NOMBRES -----*/
    
    if(text[0]!='\n'){                              //Si se cumple esta condición es porque esta al inicio del texto
      pos.push_back(0);                 
      for(int j=0;true;j++){                        //Este bucle nos permite encontrar el final del nombre hasta llegar a un :
	if(text[j]==':'){
	  names.push_back(text.substr(0,j));        //Guardamos el nombre
	  pos.push_back(j);                         //Guardamos la posición final de la palabra hasta el :
	  break;
	}
      }
    }

    for(int i=1;i<text.size();i++){             //Realzamos toda la operación anterior pero sobre todo el texto
      
      if(text[i-1]=='\n' && text[i-2]=='\n'){   //Por si un parrafo esta separado con doble enter
	pos.push_back(i);                       //Guardamos la posición inicial de la palabra
	for(int j=i;true;j++){                  //El bucle empieza desde la posición de la primera palabra de cada parrafo
	  if(text[j]==':'){
	    names.push_back(text.substr(i,j-i));
	    pos.push_back(j);
	    break;
	  }
	  else if(j==text.size())             //Si se cumple este condicional es porque ya llego al final del texto
	      break;
	}
      }
    }
    
    for(int i=pos.size()-1;i>0;i-=2)          //Este bucle nos permite eliminar los nombres de los parrafos para luego realizar la respectiva tabla
      text.erase(pos[i-1],pos[i]+2-pos[i-1]);
  }
  
  void Datos::get_text(){cout << text << endl;}

  /*
  vector<string> Datos::get_names(){
    vector<int> pos;
    
    
    if(text[0]!='\n'){                              //Si se cumple esta condición es porque esta al inicio del texto
      pos.push_back(0);                 
      for(int j=0;true;j++){                        //Este bucle nos permite encontrar el final del nombre hasta llegar a un :
	if(text[j]==':'){
	  names.push_back(text.substr(0,j));        //Guardamos el nombre
	  pos.push_back(j);                         //Guardamos la posición final de la palabra hasta el :
	  break;
	}
      }
    }

    for(int i=1;i<text.size();i++){             //Realzamos toda la operación anterior pero sobre todo el texto
      
      if(text[i-1]=='\n' && text[i-2]=='\n'){   //Por si un parrafo esta separado con doble enter
	pos.push_back(i);                       //Guardamos la posición inicial de la palabra
	for(int j=i;true;j++){                  //El bucle empieza desde la posición de la primera palabra de cada parrafo
	  if(text[j]==':'){
	    names.push_back(text.substr(i,j-i));
	    pos.push_back(j);
	    break;
	  }
	  else if(j==text.size())             //Si se cumple este condicional es porque ya llego al final del texto
	      break;
	}
      }
    }
    
    for(int i=pos.size()-1;i>0;i-=2)          //Este bucle nos permite eliminar los nombres de los parrafos para luego realizar la respectiva tabla
      text.erase(pos[i-1],pos[i]+2-pos[i-1]); 
    return names;
    }*/
  
  vector<string> Datos::get_paragraph(){
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
  
  

  vector< vector<string> > Datos::get_word_matrix0(){
    vector<string> word_vector;
    vector< vector<string> > word_matrix;
    vector<string> final_word_vector;
    vector< vector<string> > final_word_matrix;
    string word;
    int temp=0;                                                                 //Indica el indice con el cual empieza una palabra
    
    //Esta primera sección genera una matriz con todas las palabras
    
    for(int j=0;j<get_paragraph().size();j++){                                  //Este primer bucle retorna la matriz de vectores fila
      for(int i=0;i<(get_paragraph()[j]).size();i++){                             //Este segundo bucle retorna un vector fila por cada parrafo
	
	/*-------------------------------------------- Sección de simbolos ----------------------------------------*/
	
	if(get_paragraph()[j][i]=='.' || get_paragraph()[j][i]==',' ||
	   get_paragraph()[j][i]==')' || get_paragraph()[j][i]=='!' ||
	   get_paragraph()[j][i]=='?' || get_paragraph()[j][i]==':' ||
	   get_paragraph()[j][i]==';'){                                           //Si una palabra termina con punto, coma, sign interrogración, etc.
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
    
    
    //Se realiza todo un recorrido en la matriz de palabras para cambiar las primeras letras a minusculas
    
    for(int i=0;i<word_matrix.size();i++)
      for(int j=0;j<word_matrix[i].size();j++){
	char Cstring;                                                          
	Cstring=tolower(word_matrix[i][j][0]);                                  //Convertimos la primeta letra de word_matrix[i][j] en minuscula
	string String;                                                          
	String=Cstring;                                                         //Asignamos a String la letra en minuscula Cstring
	word_matrix[i][j].replace(0,1,String);                                  //Remplazamos la primera letra en la letra original pero en minuscula
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
    // Anteriormente se pasa como parametro por referencia la matriz frequency_matrix0,
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
      frequency_matrix0.push_back(frequency_vector);                //Guardamos el vector en la matriz frequency_matrix0
      frequency_vector.clear();                                    //Limpiamos el vector para poder iniciar otra vez el bucle
    }
    
    return final_word_matrix;
  }
  
  vector< vector<int> > Datos::get_frequency_matrix0(){return frequency_matrix0;}
  
  vector<string> Datos::get_word_vector1(){
    
    vector<string> word_vector;
    vector<string> final_word_vector;
    vector< vector<string> > word_matrix = get_word_matrix0();
    int count=0;
    
    for(int i=0;i<word_matrix.size();i++)
      for(int j=0;j<word_matrix[i].size();j++)                         //Este bucle es para poner todas las palabras en una lista
	word_vector.push_back(word_matrix[i][j]);
    
    // La idea de esta busqueda es que se haga el bucle respecto a la lista que tiene
    //   las palabras guardadas p. ej, se deja constante la palabra word_vector[3] y se
    //   realiza el bucle sobre las palabras guardadas en final_word_vector como se puede
    //   observar en este segundo bucle
    
    final_word_vector.push_back(word_vector[0]);
    
    for(int i=0;i<word_vector.size();i++){                             //Este primer bucle corre sobre el vector word_vector
      count=0;                                                         //Esta variable contara las veces que no se repita la cadena
      for(int j=0;j<final_word_vector.size();j++)                      //Este segundo bucle correra sobre el nuevo vector
	if(final_word_vector[j]!=word_vector[i]){                      //Si se cumple esta condición es porque la palabra es difernte a las guardadas en final_word_vector                            
	  count++;
	}
      if(count==final_word_vector.size())                              //Si se da esta condición es porque no se repite la palabra de word_vector con ninguna de las palabras de final_word_vector
	final_word_vector.push_back(word_vector[i]);                   //Se guarda la palabra
    }
    
    
    return final_word_vector;
  }
  
  vector< vector<int> > Datos::get_frequency_matrix1(){
    
    
    vector<int> frequency_vector1;
    vector<string> word_vector = get_word_vector1();
    vector< vector<string> > word_matrix = get_word_matrix0();
    int count=0;
    vector< vector<int> > fauxiliar;
    
    if(frequency_matrix1.empty()){
      for(int k=0;k<word_matrix.size();k++){                               //Primer bucle corre sobre las filas de la matriz word_matrix
	for(int j=0;j<word_vector.size();j++){                             //Segundo bucle corre sobre los elementos del vector word_vector
	  for(int i=0;i<word_matrix[k].size();i++){                        //Tercer bucle corre sobre las columnas de word_matrix
	    if(word_matrix[k][i]==word_vector[j])                          //Si esta condición se cumple es porque la palabra en la lista word_vector esta en el primer parrafo del texto
	      frequency_vector1.push_back(frequency_matrix0[k][i]);        //De esta manera se guarda el valor de la frecuencia de esta palabra en este vector
	    else
	      count++;                                                     //Si la palabra no es igual entonces se realiza un conteo
	  }
	  if(count==word_matrix[k].size())                                 //Si esta condición se cumple es porque el parrafo no contiene la palabra que se busca en la lista
	    frequency_vector1.push_back(0);                                //Por lo tanto se coloca como frecuencia cero
	  count=0;
	}
	frequency_matrix1.push_back(frequency_vector1);
	frequency_vector1.clear();
      }
      fauxiliar=frequency_matrix1;
    }
    else
      fauxiliar=frequency_matrix1;
    return fauxiliar;
  }
  
  
  void Datos::save_file1(string name_file1){
    fstream out_file;
    out_file.open(name_file1,ios::out);
    vector<string> word_vector1 = get_word_vector1();
    
    if(frequency_matrix1.empty())
      get_frequency_matrix1();
    out_file << " ";
    for(int i=0;i<word_vector1.size();i++)            //Guardamos en el archivo de salida las palabras separadas por espacio, por ejemplo, si tu estas todo parrafo ..
      out_file << word_vector1[i] << " ";
    out_file << endl;
    
    
    for(int i=0;i<frequency_matrix1.size();i++){     //Guardamos los datos separados por espacio, de modo que paresera una tabla.
      out_file << names[i] << " ";
      for(int j=0;j<frequency_matrix1[i].size();j++)
	out_file << frequency_matrix1[i][j] << " ";
      out_file << endl;
    }
    
    out_file.close();
  }
  
} //Fin del namespace OpenTxT

 
