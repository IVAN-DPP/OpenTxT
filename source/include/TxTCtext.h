#ifndef TXTCTEXT_H
#define TXTCTEXT_H

#include <string>
#include "TxText.h"

class TxTCtext{
 private:
  std::string Ctext; 
 public:
  TxTCtext(TxText);
  TxTCtext(std::string);
  void LowercaseA();        // Lowercase All
  void UppercaseA();        // Uppercase All
  void PunctuationR();      // Punctuation remove
  void ExclamationR();      // Exclamation remove
  std::string GetText();
};

#endif
