#include "/home/...../texto/palabras.h"
int main(){

  //Acentos a("Pá ré Putá quep te pário    ");
  Acentos a;
  a.text_file("prb.txt");
  string text;
  text = a.load_file();
  string new_text = a.get_text_w();
  
  cout << text << endl << "--------\n" << new_text << endl;

  a.get_text_m(&new_text);

  cout << "\n------------------\n" << new_text << endl; 
  Palabra r("texto");
  r.load_text(new_text);
  vector<size_t> position= r.get_pos();

  cout << "Las veces que se repite la palabra texto son: " << r.get_freq(position) << endl;
    

  return 0;
}
