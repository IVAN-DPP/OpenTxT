
/*La idea por el momento es que cada parrafo represente la respuesta abierta de cada persona
  por lo que el texto debe tener las siguientes consideraciones:

  1) No debe tener el nombre o algo que lo identifique al inicio del texto, por ejemplo,
  Daniel: Yo soy daniel y ....       ERRONEO
  Yo soy daniel y ....               Correcto
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
  //Paso 2:
  //Se debe generar estas dos funciones base para la creación de las matrices de palabras por parrafo y sus frecuencias
  a.get_word_matrix0();     
  a.get_frequency_matrix0();

  //Paso 3:
  //Se genera la tabla de contingencia de forma que cada fila representa un parrafo, y las columnas
  // representan las palabras sin repetir en todo el texto, cada elemento de esta matriz representa
  // las frecuencias de estas palabras por parrafo.
  a.get_word_vector1();
  a.get_frequency_matrix1();
  a.save_file1();
  return 0;
}
