
/*La idea por el momento es que cada parrafo represente la respuesta abierta de cada persona
  por lo que el texto debe tener las siguientes consideraciones:

  1) Debe tener el nombre o algo que lo identifique al inicio del texto, por ejemplo separado por doble punto
  Daniel: Yo soy daniel y ....      Correcto
  ParrafoPrimero: un textos ...     Correcto
  
  2) Toda la respuesta debe ir sobre un mismo parrafo, ya que si se deja por diferentes parrafos
  el programa lo detectara como una persona diferente

  Estas consideraciones seran tratadas mas adelante igual que el análisis de datos realizado por
  herramientas de C++ como Armadillo y graficadores como Gnuplot.

  */

#include "datos.h"

using namespace OpenTxT;

int main(){


  //Paso 1: Cargar el texto
  Datos a("textos.txt"); //Nombre del texto
  a.load_text();       //Carga el texto
  // //Paso 2:
  // //Se debe generar estas dos funciones base para la creación de las matrices de palabras por parrafo y sus frecuencias
  // a.get_word_matrix0();     
  // a.get_frequency_matrix0();

  // //Paso 3:
  // //Se genera la tabla de contingencia de forma que cada fila representa un parrafo, y las columnas
  // // representan las palabras sin repetir en todo el texto, cada elemento de esta matriz representa
  // // las frecuencias de estas palabras por parrafo.
  //a.get_names();
  //a.get_text();
  /*  for(int i=0;i<a.get_names().size();i++)
    cout << a.get_names()[i] << endl;*/
  a.save_file1("datos1.txt"); //Guardamos la tabla en un archivo llamado datos1.txt
  return 0;
}
