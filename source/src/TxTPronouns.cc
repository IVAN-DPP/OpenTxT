
#include "../include/TxTPronouns.h"

#include<vector>
#include<string>

TxTPronouns::TxTPronouns(){}

std::vector<std::string> TxTPronouns::GetPronounsU(){
  PronounsU.push_back("YO");
  PronounsU.push_back("TU");
  PronounsU.push_back("EL");
  PronounsU.push_back("ELLA");
  PronounsU.push_back("USTED");
  PronounsU.push_back("NOSOTROS");
  PronounsU.push_back("VOSOTROS");
  PronounsU.push_back("ELLOS");
  PronounsU.push_back("ELLAS");
  PronounsU.push_back("USTEDES");

  return PronounsU;
}

