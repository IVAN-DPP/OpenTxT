
#include "../include/TxTPronouns.h"

#include<vector>
#include<string>

TxTPronouns::TxTPronouns(){}

std::vector<std::string> TxTPronouns::GetPronounsU(){
  
  //Nominamtivos
  PronounsU.push_back("YO");
  PronounsU.push_back("TU");
  PronounsU.push_back("EL");
  PronounsU.push_back("ELLA");
  PronounsU.push_back("LO");
  PronounsU.push_back("USTED");
  PronounsU.push_back("NOSOTROS");
  PronounsU.push_back("NOSOTRAS");
  PronounsU.push_back("VOSOTROS");
  PronounsU.push_back("VOSOTRAS");
  PronounsU.push_back("ELLOS");
  PronounsU.push_back("ELLAS");
  PronounsU.push_back("USTEDES");

  //Acustativos

  PronounsU.push_back("ME");
  PronounsU.push_back("TE");
  PronounsU.push_back("LO");
  PronounsU.push_back("LA");
  PronounsU.push_back("NOS");
  PronounsU.push_back("OS");
  PronounsU.push_back("LOS");
  PronounsU.push_back("LAS");

  //Dativo

  PronounsU.push_back("LE");
  PronounsU.push_back("LES");
  PronounsU.push_back("LAS");

  //Preoposicional

  PronounsU.push_back("MI");
  PronounsU.push_back("TI");
  PronounsU.push_back("ELLO");
  return PronounsU;
}

