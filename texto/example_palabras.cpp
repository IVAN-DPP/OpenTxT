/***********************************************

@autor: IVAN DARIO PIERNAGORDA PEÑA

************************************************/

#include "palabras.h"
int main(){
  
  Acentos a;
  a.text_file("prb.txt");
  string text;
  text = a.load_file();
  string new_text = a.get_text_w();
  
  cout << text << endl << "--------\n" << new_text << endl;

  a.get_text_m(&new_text);

  cout << "\n------------------\n" << new_text << endl; 
  Palabra r("texto");
  
  r.load_text(new_text);
  vector<size_t> position= h[0].get_pos();

  cout << "Las veces que se repite la palabra texto son: " << h[0].get_freq(position) << endl;
    

  return 0;
}


/*
    example_palabras.cpp is part of OpenTxT.

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
