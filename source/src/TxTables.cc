
#include<string>
#include<map>
#include<iostream>
#include "../include/TxTables.h"
#include "../include/TxTypes.h"
#include"../include/TxTPronouns.h"
#include"../include/TxTPrepositions.h"
#include"../include/TxTConjunctions.h"

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

void TxTables::PronounsUR(){

  TxTPronouns Pronouns;
  std::vector<std::string> PronVector;
  PronVector=Pronouns.GetPronounsU();
  int temp=0;                            //This variable will count the Pronouns amount
  for(int i=0;i<PronVector.size();i++){
    std::map<std::string,int>::iterator itr;
    itr=Table.find(PronVector[i]);
    
    if(itr!=Table.end()){
      Table.erase(itr);
      temp++;
    }
  }
  std::cout << "Pronouns amount removed: " << temp << std::endl;
}

void TxTables::PrepositionsUR(){

  TxTPrepositions Prepositions;
  std::vector<std::string> PrepVector;
  PrepVector=Prepositions.GetPrepositionsU();
  int temp=0;                            //This variable will count the Prepositions amount
  for(int i=0;i<PrepVector.size();i++){
    std::map<std::string,int>::iterator itr;
    itr=Table.find(PrepVector[i]);
    
    if(itr!=Table.end()){
      Table.erase(itr);
      temp++;
    }
  }
  std::cout << "Prepositions amount removed: " << temp << std::endl;
  
}


void TxTables::ConjunctionsUR(){

  TxTConjunctions Conjunctions;
  std::vector<std::string> ConjVector;
  ConjVector=Conjunctions.GetConjunctionsU();
  int temp=0;                            //This variable will count the Prepositions amount
  for(int i=0;i<ConjVector.size();i++){
    std::map<std::string,int>::iterator itr;
    itr=Table.find(ConjVector[i]);
    
    if(itr!=Table.end()){
      Table.erase(itr);
      temp++;
    }
  }
  std::cout << "Conjunctions amount removed: " << temp << std::endl;
  
}
