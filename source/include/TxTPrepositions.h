
#ifndef TXTPREPOSITIONS_H
#define TXTPREPOSITIONS_H

#include<vector>
#include<string>

struct TxTPrepositions{
private:
  std::vector<std::string> PrepositionsU;
  std::vector<std::string> PrepositionsL;
public:
  TxTPrepositions();
  std::vector<std::string> GetPrepositionsU();
  std::vector<std::string> GetPrepositionsL();
};

#endif
