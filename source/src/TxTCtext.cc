
#include "../include/TxTCtext.h"
#include "../include/TxText.h"

#include<string>
#include<cctype>
#include<stdlib.h>


TxTCtext::TxTCtext(TxText Text){
  Ctext=Text.GetText();
  for(int i=Ctext.size();true;i--){
   
    if(Ctext[i-2]!='\n' && Ctext[i-2]!=' ') break;
    Ctext.pop_back();
  }
  Ctext.pop_back();
  Ctext.push_back('\t');
}

TxTCtext::TxTCtext(std::string Text){
  Ctext=Text;
  for(int i=Ctext.size();true;i--){
   
    if(Ctext[i-2]!='\n' && Ctext[i-2]!=' ') break;
    Ctext.pop_back();
  }
  Ctext.pop_back();
  Ctext.push_back('\t');
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
       Ctext[i]=='-' || Ctext[i]=='_' ||
       Ctext[i]==';' || Ctext[i]=='\'')
      Ctext.replace(i,1," ");
    
    else if(Ctext.substr(i,2)=="¡" || Ctext.substr(i,2)=="¿" ||
	    Ctext.substr(i,2)=="«" || Ctext.substr(i,2)=="»")      //The symbols ¡ and ¿ have two caracteres
      Ctext.replace(i,2," ");
  }
}

void TxTCtext::ExclamationR(){

  for(int i=0;i<Ctext.size();i++){
    if(Ctext.substr(i,2)=="á")
      Ctext.replace(i,2,"a");
    else if(Ctext.substr(i,2)=="é")
      Ctext.replace(i,2,"e");
    else if(Ctext.substr(i,2)=="í")
      Ctext.replace(i,2,"i");
    else if(Ctext.substr(i,2)=="ó")
      Ctext.replace(i,2,"o");
    else if(Ctext.substr(i,2)=="ú")
      Ctext.replace(i,2,"u");

    else if(Ctext.substr(i,2)=="Á")
      Ctext.replace(i,2,"A");
    else if(Ctext.substr(i,2)=="É")
      Ctext.replace(i,2,"E");
    else if(Ctext.substr(i,2)=="Í")
      Ctext.replace(i,2,"I");
    else if(Ctext.substr(i,2)=="Ó")
      Ctext.replace(i,2,"O");
    else if(Ctext.substr(i,2)=="Ú")
      Ctext.replace(i,2,"U");
  }

}

std::string TxTCtext::GetText(){
  return Ctext;
}
