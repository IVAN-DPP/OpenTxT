#ifndef TXTCONJUNCTIONS_H
#define TXTCONJUNCTIONS_H

#include<vector>
#include<string>

struct TxTConjunctions{
private:
  std::vector<std::string> ConjunctionsU;
  std::vector<std::string> ConjunctionsL;
public:
  TxTConjunctions();
  std::vector<std::string> GetConjunctionsU();
  std::vector<std::string> GetConjunctionsL();  
};

#endif
