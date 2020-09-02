#include "../include/TxText.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

TxText::TxText(std::string TN): TextsName(TN){}

void TxText::SetTextName(string tn){
  TextsName=tn;
}

string TxText::GetTextName(){
  return TextsName;
}

void TxText::LoadText(){
  
  if(Text.empty()){
    fstream input_file;
    //string Text;
    
    input_file.open(TextsName,ios::in);
    
    if(input_file.fail()){
      cout << "We can't load the file " << TextsName <<"\n";
      exit(0);    
    }
    getline(input_file,Text,'\0');
  }

}

string TxText::GetText(){
  return Text;
}
