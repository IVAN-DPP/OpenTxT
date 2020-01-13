/***********************************************

@autor: IVAN DARIO PIERNAGORDA PEÑA

************************************************/
#include "acentos.h"


class Palabra : public Acentos{ 
private:
  string text,word;
public:

  /*----- METHODS ---------*/
  //Constructor
  Palabra();
  Palabra(string);    //Texto en minuscula y sin tildes

  //Load

  void load_text(string);

  //get

  vector<string> get_words(vector<size_t>); //Devuelve palabras con la posición definida en el vector que esta como referencia
  virtual vector<size_t> get_pos(); //Devuelve un vector con la posición de la palabra
  double get_freq(vector<size_t>); //Devuelve las veces que se repite la palabra
  
  
};

Palabra::Palabra(){}
Palabra::Palabra(string Word){word=Word;}

void Palabra::load_text(string Text){text=Text;}

/*Esta función nos devuelve un vector con palabras, la idea es que el vector que se recibe sea el vector con las posiciones de la palabra a buscar */
vector<string> Palabra::get_words(vector<size_t> temp){
  vector<string> words(temp.size());
  int count=0;
  for(int j=0;j<temp.size();j++){
    
    for(int i=0;true;i++){
      if(text[temp[j]+i]!=' ')
	count++;
      else
	break;
    }
    words[j]=text.substr(temp[j],count);
    count=0;
  }
    
  return words;
}

/* 1) Se recibira la palabra a buscar, se buscara la primera letra de la palabra sobre todo el texto con la función heredada get_pos_x_v
   2) Se pondra la condición de que si existe una letra antes de la buscada entonces no guardara su posición.
   
   pablo -> palabra a buscar
   p     -> primera letra
   opo   -> palabra con p, esta posición no se guarda ya que no empieza con p.

   3) Se utiliza la función get_words para comparar las palabras guardadas en este con la palabra que queremos buscar (Esta esta en private y es word), si la palabra no es igual el elemento del vector temp se cambia a 971102 mostrando que las palabras no son iguales.
   
   4) Utilizamos el metodo de la burbuja para ordenar los números en el vector temp

   5) Eliminamos los elementos que tengan como número 971102
*/

vector<size_t> Palabra::get_pos(){
  /*--------------- Primera y segunda parte ---------------*/
  int Temp=0;
  vector<size_t> pos=get_pos_x_v(word.substr(0,1),&text);
  vector<size_t> temp(pos.size());

  for(int i=0;i<pos.size();i++){
    if(i==0 && pos[0]==0){
      //cout << "bien" << endl;
      temp[Temp]=pos[i];
      Temp++;
    }
    else{
      if(text[pos[i]-1]==' '){
	//cout << "bien" << endl;
	temp[Temp]=pos[i];
	Temp++;
      }
    }
  }
  //Este bucle se coloca para eliminar el ultimo elemento del vector si es cero
  for(int i=pos.size()-1;i>=0;i--){
    if(temp[i]==0)
      temp.pop_back();
    else
      break;
  }
  /*----------------- Tercera parte -------------------------*/
  vector<string> words = get_words(temp);
  for(int i=0;i<words.size();i++){
    if(words[i]!=word)
      temp[i]=971102;
    
  }

  /*----------------- Cuarta parte --------------------------*/
  int var_temp,k;          //k contara las veces que se tuvo que hacer algun cambios.
  
  while(true){

    for(int i=0;i<temp.size()-1;i++){
      k=0;
      if(temp[i]>temp[i+1]){
	var_temp=temp[i];
	temp[i]=temp[i+1];
	temp[i+1]=var_temp;
	k++;
        
      }
    }
    if(k==0)
      break;
  }
  /*--------- Quinta parte ----------------*/
  for(int i=0;i<pos.size();i++)
    if(temp[i]==971102)
      temp.pop_back();
  
  return temp;
}

double Palabra::get_freq(vector<size_t> temp){return temp.size();}

/*
    palabras.h is part of OpenTxT.

    OpenTxT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenTxT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenTxT.  If not, see <https://www.gnu.org/licenses/>.
*/
