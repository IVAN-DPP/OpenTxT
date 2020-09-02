
#include "include/TxText.h"
#include "include/TxTCtext.h"
#include "include/TxTypes.h"
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

  // The class TxTCext work fine

  TxTCtext *CTex;
  CTex = new TxTCtext(*tex);
  cout <<"1: " <<CTex->GetText() << endl;
  CTex->LowercaseA();
  cout << "2: " <<CTex->GetText() << endl;
  CTex->UppercaseA();
  cout << "3: " <<CTex->GetText() << endl;
  CTex->PunctuationR();
  cout << "4: " <<CTex->GetText() << endl;
  CTex->ExclamationR();
  cout << "5: " <<CTex->GetText() << endl;
  CTex->UppercaseA();
  cout << "6: " <<CTex->GetText() << endl;

  //--------------------------------------//

  //--------------------------------------//
  TxTypes *t = new TxTypes(*CTex);
  //--------------------------------------//
  return 0;
}
