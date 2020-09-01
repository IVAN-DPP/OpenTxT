
#include "include/TxText.h"
#include "include/TxTCtext.h"
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

  //-----------------------------//

  TxTCtext *CTex;
  CTex = new TxTCtext(*tex);
  cout << CTex->GetText() << endl;
  CTex->LowercaseA();
  cout << CTex->GetText() << endl;
  CTex->UppercaseA();
  cout << CTex->GetText() << endl;
  return 0;
}
