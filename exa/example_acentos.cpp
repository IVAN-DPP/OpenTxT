/***********************************************

@autor: IVAN DARIO PIERNAGORDA PEÑA

************************************************/

#include "/home/...../texto/acentos.h" 
#include <iostream>

using namespace std;

int main(){
  //Acentos a("Lá ré Putá que te pário");
  Acentos a;
  a.text_file("prb.txt");
  string text;
  text = a.load_file();
  string new_text = a.get_text_w();
  
  cout << text << endl << "--------\n" << new_text << endl;

  a.get_text_m(&new_text);

  cout << "\n------------------\n" << new_text << endl; 
  
  

  return 0;
}


/*
    example_acentos.cpp is part of OpenTxT.

    OpenTxT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenTxT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenTxT.  If not, see <https://www.gnu.org/licenses/>.

 */
