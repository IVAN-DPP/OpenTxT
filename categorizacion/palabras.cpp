#include<c++/8/iostream>
#include"/home/elchorco/Documents/c++/ProyPalabras/PALABRAS/texto/acentos.h"

using namespace std;

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

  virtual vector<size_t> get_pos(); //Devuelve un vector con la posición de la palabra
  double get_num_l(); //Número de letras en una palabra
  
};

Palabra::Palabra(){}
Palabra::Palabra(string Word){word=Word;}

void Palabra::load_text(string Text){text=Text;}

/* 1) Se recibira la palabra a buscar, se buscara la primera letra de la palabra sobre todo el texto con la función heredada get_pos_x_v
   2) Se pondra la condición de que si existe una letra antes de la buscada entonces no guardara su posición.
   
   pablo -> palabra a buscar
   p     -> primera letra
   opo   -> palabra con p, esta posición no se guarda ya que no empieza con p.

   3)
*/

vector<size_t> Palabra::get_pos(){
  /*--------------- Primera y segunda parte ---------------*/
  int Temp=0;
  vector<size_t> pos=get_pos_x_v(word.substr(0,1),&text);
  vector<size_t> temp(pos.size());

  for(int i=0;i<pos.size();i++){
    if(pos[0]==0){
      cout << "bien" << endl;
      temp[Temp]=pos[i];
      Temp++;
    }
    else{
      if(text[pos[i]-1]==' '){
	cout << "bien" << endl;
	temp[Temp]=pos[i];
	Temp++;
      }
    }
  }

  for(int i=1;i<temp.size();i++){
    

  }
  return pos;
}
double Palabra::get_num_l(){
  
  return 0;
}

int main(){

  Acentos a("Pá ré Putá que te pário");
  //Acentos a;
  //a.text_file("prb.txt");
  string text;
  text = a.load_file();
  string new_text = a.get_text_w();
  
  cout << text << endl << "--------\n" << new_text << endl;

  a.get_text_m(&new_text);

  cout << "\n------------------\n" << new_text << endl; 
  Palabra r("puta");
  r.load_text(new_text);
  vector<size_t> lll= r.get_pos();
  for(int i=0;i<lll.size();i++)
    cout << lll[i] << endl;

  string popo("lopol");

  cout << popo.find("p",0) << endl;

  return 0;
}
