#ifndef TXTABLES_H
#define TXTABLES_H

#include<map>
#include<string>
#include"../include/TxTypes.h"

class TxTables{
 private:
  std::map<std::string,int> Table;
  std::vector<std::string> Pvector;
  std::map<std::string,std::vector<int>> MapPrintTable;
 public:
  TxTables(TxTypes);
  TxTables(std::vector<std::string>);
  void GetTable(std::string);
  std::map<std::string,int> GetMap();
  void PronounsUR();
  void PrepositionsUR();
  void ConjunctionsUR();
  void Compare(std::map<std::string,std::vector<int>>&,std::map<std::string,int>,int,int);
  void PrintTable(std::string,int = 1);
};


#endif
