#ifndef TXTABLES_H
#define TXTABLES_H

#include<map>
#include<string>
#include"../include/TxTypes.h"

class TxTables{
 private:
  std::map<std::string,int> Table;
  std::vector<std::string> Pvector;
 public:
  TxTables(TxTypes);
  TxTables(std::vector<std::string>);
  void GetTable(std::string);
};


#endif
