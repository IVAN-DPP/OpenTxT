
#include "include/TxText.h"
#include "include/TxTCtext.h"
#include "include/TxTypes.h"
#include "include/TxTPronouns.h"
#include "include/TxTables.h"
#include<string>
#include<iostream>
#include<chrono>

std::vector<std::string> Files(std::string);
void MultipleFiles(std::vector<std::string>,std::map<std::string,std::vector<int>>&);

using namespace std;

int main(int argc, char** argv){
  map<string,vector<int>> Map;
  MultipleFiles(Files(argv[1]),Map);
  return 0;
}


vector<string> Files(string file){
  TxText *input = new TxText(file);
  input->LoadText();
  TxTCtext *Text = new TxTCtext(*input);
  TxTypes *List = new TxTypes(*Text);
  return List->GetWordVector();
  //return List->GetWordVector();
}

void MultipleFiles(vector<string> ListF,map<string,vector<int>> &Map){
  vector<string> List = ListF;
  TxTables *PrintTable;
  for(int i=0;i<List.size();i++){
    
    TxText *tex = new TxText(List[i]);;
    tex->LoadText();
    
    TxTCtext *CTex = new TxTCtext(*tex);
    CTex->LowercaseA();
    CTex->UppercaseA();
    CTex->PunctuationR();
    CTex->ExclamationR();
    CTex->UppercaseA();

    //--------------------------------------//
    //Timer Time;
    TxTypes *t = new TxTypes(*CTex);
    //--------------------------------------//
    //map<string,int*> Map;
    TxTables *Table =new TxTables(*t);
    Table->GetTable("frequency");
    Table->PronounsUR();
    Table->PrepositionsUR();
    Table->ConjunctionsUR();
    Table->Compare(Map,Table->GetMap(),i,List.size());
    PrintTable=Table;
    // for(std::map<std::string,vector<int>>::iterator itr=Map.begin();itr!=Map.end();itr++)
    //   std::cout << itr->first << "\t\t\t\t"
    // 		<< Map[itr->first][0] 
    // 		<< Map[itr->first][1] 
    // 		<< Map[itr->first][2] << std::endl;
    // cout << "--------------------\n";
  }
  PrintTable->PrintTable("SALIDA.txt",List.size());
}

