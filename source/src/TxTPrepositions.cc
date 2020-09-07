#include "../include/TxTPrepositions.h"
#include<vector>
#include<string>

TxTPrepositions::TxTPrepositions(){}

std::vector<std::string> TxTPrepositions::GetPrepositionsU(){

  //Lugar
  PrepositionsU.push_back("A");
  PrepositionsU.push_back("DE");
  PrepositionsU.push_back("EN");
  PrepositionsU.push_back("ENTRE");
  PrepositionsU.push_back("HACIA");
  PrepositionsU.push_back("POR");
  PrepositionsU.push_back("TRAS");

  //Tiempo

  PrepositionsU.push_back("CON");
  PrepositionsU.push_back("DESDE");
  PrepositionsU.push_back("PARA");
  PrepositionsU.push_back("SOBRE");

  return PrepositionsU;
}
