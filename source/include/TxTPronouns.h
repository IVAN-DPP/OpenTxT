#ifndef TXTPRONOUNS_H
#define TXTPRONOUNS_H


#include<vector>
#include<string>

struct TxTPronouns{

private:
  std::vector<std::string> PronounsU;
  std::vector<std::string> PronounsL;
public:
  TxTPronouns();
  std::vector<std::string> GetPronounsU();
  std::vector<std::string> GetPronounsL();
};

#endif
