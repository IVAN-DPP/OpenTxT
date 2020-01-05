#include<c++/8/iostream>
#include<c++/8/string>
#include<c++/8/fstream>
#include<c++/8/locale>
using namespace std;

int main(){
  fstream archivo_ent;
  archivo_ent.open("lol.txt",ios::in);
  string texto,*Tex;

  getline(archivo_ent,texto,';');
  Tex=&texto;
  /*
  for(size_t i=0;i<texto.size();i++)
    cout << Tex+i << endl;
  cout << texto.size() << endl;
  cout << "------------\n";
  */
  /*
  cout << texto.find("í") << endl;
  string vocal("áéíóú");
  for(size_t i=1;i<vocal.size();i++)
    cout << vocal+i << endl;
  cout << "-.-----------------\n";
  for(size_t i=1;i<texto.size();i++)
    cout << texto+i << endl;
  
  texto.insert(0," ");
  for(size_t i=0;i<texto.size();i++)
    if(texto.substr(i,i+1)==0x130)
      cout << "Si " << i << endl;
  cout << texto << endl;
  */
  std::locale::global(std::locale("spanish"));
  string a;
  int i=160;
  a=i;
  cout << a << endl;
  
  return 0;
  
}
