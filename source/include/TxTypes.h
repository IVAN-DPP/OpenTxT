#ifndef TXTYPES_H
#define TXTYPES_H

#include "../include/TxTCtext.h"
#include "../include/TxText.h"

#include<string>
#include<vector>
class TxTypes{
 private:
  std::string Ctext;
  std::vector<std::string> Pvector;
 public:
  TxTypes(TxTCtext);
  TxTypes(std::string);
};


#endif
