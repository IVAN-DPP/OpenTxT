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
  int temp=0;
  for(int i=0;i<text.size();i++){

    if(text[i]=='\n' && text[i+1]=='\n')
      continue;
    
    else if(text[i]=='\n'){
      paragraph=text.substr(temp,i);
      temp=i;
      list_of_paragraphs.push_back(paragraph);
    }
    else if(text[i]==';')
      break;
    
  }
  return list_of_paragraphs;
}

int main(){

  Prueba a("prb.txt");
  a.load_text();
  //a.get_text();
  // for(int i=0;i<(a.get_paragraph()).size();i++)
  //   cout << a.get_paragraph()[i] <<endl;
  
  return 0;
}
