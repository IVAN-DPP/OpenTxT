
#include "../include/TxTCtext.h"
#include "../include/TxText.h"

#include<string>
#include<cctype>
#include<stdlib.h>


TxTCtext::TxTCtext(TxText Text){
  Ctext=Text.GetText();
}

void TxTCtext::LowercaseA(){
  std::string CLower;
  for(int i=0;i<Ctext.size();i++)
    CLower.push_back(tolower(Ctext.at(i)));

  Ctext=CLower;
}

void TxTCtext::UppercaseA(){
  std::string CUpper;
  for(int i=0;i<Ctext.size();i++)
    CUpper.push_back(toupper(Ctext.at(i)));

  Ctext=CUpper;
}


void TxTCtext::PunctuationR(){

  for(int i=0;i<Ctext.size();i++){
    if(Ctext[i]=='.' || Ctext[i]==',' ||
       Ctext[i]=='!' || Ctext[i]==')' ||
       Ctext[i]=='?' || Ctext[i]=='(' ||
       Ctext[i]=='\"' || Ctext[i]=='#' ||
       Ctext[i]=='$' || Ctext[i]=='%' ||
       Ctext[i]=='&' || Ctext[i]=='/' ||
       Ctext[i]=='-' || Ctext[i]=='_')
      Ctext.replace(i,1," ");
    
    else if(Ctext.substr(i,2)=="¡" || Ctext.substr(i,2)=="¿")      //The symbols ¡ and ¿ have two caracteres
      Ctext.replace(i,2," ");
  }
}
std::string TxTCtext::GetText(){
  return Ctext;
}
