#include"../include/TxTConjunctions.h"

TxTConjunctions::TxTConjunctions(){}

std::vector<std::string> TxTConjunctions::GetConjunctionsU(){

  //Copulativas

  ConjunctionsU.push_back("Y");
  ConjunctionsU.push_back("E");
  ConjunctionsU.push_back("NI");

  //Adversativas

  ConjunctionsU.push_back("MAS");
  ConjunctionsU.push_back("PERO");
  ConjunctionsU.push_back("SINO");
  ConjunctionsU.push_back("QUE");

  //Disyuntivas

  ConjunctionsU.push_back("O");
  ConjunctionsU.push_back("U");

  //Causales

  ConjunctionsU.push_back("PORQUE");
  ConjunctionsU.push_back("PUES");
  ConjunctionsU.push_back("PUESTO");

  //Condicionales

  ConjunctionsU.push_back("SI");
  ConjunctionsU.push_back("CON");
  ConjunctionsU.push_back("TAL");
  ConjunctionsU.push_back("SIEMPRE");

  //Concensivas

  ConjunctionsU.push_back("AUNQUE");
  ConjunctionsU.push_back("ASI");

  //Comparativas

  ConjunctionsU.push_back("TAN");
  ConjunctionsU.push_back("TANTO");

  //Temporales

  ConjunctionsU.push_back("CUANDO");
  ConjunctionsU.push_back("ANTES");

  return ConjunctionsU;

}
