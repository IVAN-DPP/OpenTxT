
#include "../include/TxTypes.h"
#include "../include/TxTCtext.h"
#include "../include/TxText.h"

#include <iostream>

TxTypes::TxTypes(TxTCtext Text){
  Ctext=Text.GetText();
  
  int start=0;
  
  for(int i=0;i<Ctext.size();i++){
    
    if(Ctext[i]=='\t'){                                   //End of text
      Pvector.push_back(Ctext.substr(start,i-start));
      break;
    }

    if(i>0 && Ctext[i]=='\n' && Ctext[i-1]!=' ' && Ctext[i-1]!='\n'){
      Pvector.push_back(Ctext.substr(start,i-start));
      start=i+1;
      continue;
    }
    if(Ctext[i]=='\n'){                                   //If the text have \n
      start=i+1;
      continue;
    }
    if(Ctext[i-1]=='\n' && Ctext[i]==' '){
      start=i+1;
      continue;
    }
    
    if(i==0 && Ctext[i]==' ') {                           //If the text begin with a space
      start=i+1;
      continue;
    }
    
    if(Ctext[i]==' ' && Ctext[i-1]==' ' ){
      start=i+1;
      continue;
    }

    if(Ctext[i]==' '){
      Pvector.push_back(Ctext.substr(start,i-start));
      start=i+1;
    }
    
  }

  //  for(int i=0;i<Pvector.size();i++)
  //  std::cout << Pvector[i] << std::endl;
    
  
}

TxTypes::TxTypes(std::string Text){
  Ctext=Text;
  
  int start=0;
  
  for(int i=0;i<Ctext.size();i++){
    
    if(Ctext[i]=='\t'){                                   //End of text
      Pvector.push_back(Ctext.substr(start,i-start));
      break;
    }
    
    if(i>0 && Ctext[i]=='\n' && Ctext[i-1]!=' ' && Ctext[i-1]!='\n'){
      Pvector.push_back(Ctext.substr(start,i-start));
      start=i+1;
      continue;
    }
    if(Ctext[i]=='\n'){                                   //If the text have \n
      start=i+1;
      continue;
    }
    if(Ctext[i-1]=='\n' && Ctext[i]==' '){
      start=i+1;
      continue;
    }
    
    if(i==0 && Ctext[i]==' ') {                           //If the text begin with a space
      start=i+1;
      continue;
    }
    
    if(Ctext[i]==' ' && Ctext[i-1]==' ' ){
      start=i+1;
      continue;
    }
    
    if(Ctext[i]==' '){
      Pvector.push_back(Ctext.substr(start,i-start));
      start=i+1;
    }
    
  }
    
}
