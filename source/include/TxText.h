
#ifndef TXTEXT_H
#define TXTEXT_H

#include<string>

class TxText{
protected:
  std::string TextsName = "Nada.txt";
  std::string Text;
public:
  TxText(std::string);
  void SetTextName(std::string);
  std::string GetTextName();
  void LoadText();
  std::string GetText();
};

#endif

