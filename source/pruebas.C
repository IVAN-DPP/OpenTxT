
#include "include/TxText.h"
#include<string>
#include<iostream>

using namespace std;
int main(){
  // The class TxText work fine
  TxText *tex;
  tex = new TxText("Nada.txt");
  cout << tex->GetTextName() << endl;
  tex->SetTextName("Halo.txt");
  cout << tex->GetTextName() << endl;
  //tex->LoadText();
  tex->SetTextName("pp.txt");
  tex->LoadText();
  cout << tex->GetText() << endl;

  //----------------------------//
  return 0;
}
