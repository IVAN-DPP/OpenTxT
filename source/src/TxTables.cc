
#include<string>
#include<map>
#include<iostream>
#include "../include/TxTables.h"
#include "../include/TxTypes.h"

TxTables::TxTables(TxTypes Type){
  Pvector=Type.GetWordVector();
}

TxTables::TxTables(std::vector<std::string> Vec){
  Pvector=Vec;
}

void TxTables::GetTable(std::string op1){

  for(int i=0;i<Pvector.size();i++){

    std::map<std::string,int>::iterator itr;
    itr=Table.find(Pvector[i]);

    if(itr!=Table.end())
      (itr->second)++;  
    else
      Table.insert(std::pair<std::string,int>(Pvector[i],1));
  }

  // for(std::map<std::string,int>::iterator itr=Table.begin();itr!=Table.end();itr++)
  //   std::cout << itr->first << "\t" << itr->second << std::endl;
  
}
