#include<iostream>
#include<string>
#include<fstream>
#include<locale.h>
#include<stdlib.h>
#include<cctype> //Libreria para tolower
using namespace std;

int main(){
  int i,j,h,k, conteo;
  fstream archivo_ent, archivo_sal;
  string nom_archivo, caracter, var_prob;
  string texto;

/********** ITEM UNO **************/

  cout << "Ingrese el nombre del archivo de entrada\n";
  getline(cin,nom_archivo);
  archivo_ent.open(nom_archivo,ios::in);
  getline(archivo_ent,texto,';');

  cout << "Escriba la palagra o número a buscar\n";
  cin >> caracter;

/************ITEM DOS****************/
/*Comentario extraño: La primera letra no puede ser una vocal!!!!!!!!!!!!!!!!!!!!!!!
Se define var_prob como una variable provicional para eliminarl la primera letras
desde el inicio y volverla a concatenar al final de toda la transformación*/
  if(texto.substr(0,2)=="á"){
    var_prob="a";
    texto.replace(0,2,"");
  }
  else if(texto.substr(0,2)=="é"){
    var_prob="e";
    texto.replace(0,2,"");
  }
  else if(texto.substr(0,2)=="í"){
    var_prob="i";
    texto.replace(0,2,"");
  }
  else if(texto.substr(0,2)=="ó"){
    var_prob="o";
    texto.replace(0,2,"");
  }
  else if(texto.substr(0,2)=="ú"){
    var_prob="u";
    texto.replace(0,2,"");
  }

  else if(texto.substr(0,1)=="a" || texto.substr(0,1)=="e" || texto.substr(0,1)=="i"
        || texto.substr(0,1)=="o" || texto.substr(0,1)=="u"){
        var_prob=texto.substr(0,1);
        texto.replace(0,1,"");
   }


/*****************************************************************
1) Se genera un for para realizar iteraciones de dos en dos en k,
para escoger la vocal del objeto cadena "vocal_con", de dos en dos
porque la letra con tilde cuenta como dos, la letra y la tilde
por separado, cuando es cero empieza en a y cuando es uno termina en "´".
2) Esto con el fin de que vocal_con.substr() tenga la cadena de alguna
de las letras con tilde. P.E vocal_con.substr(0,2)="á".
3) Esto me genera un conteo que es el primero for dentro de cada switch,
 cuenta cuantas veces hay esa letra con tilde en el texto.
4) El conteo nos sirve para generar la condición de frontera de la iteración
del tercer for.
5) El tercer for cambia la palabra con texto.replace() con la letra sin
tilde.
******************************************************************/

string vocal_con("áéíóú");
for(k=0;k<=8;k+=2)  //Primer for
{
  switch (k) {
    case 0:
     conteo=-1;
     h=0;
     j=0;
     for(i=0;i<texto.length();i++){ //segundo for
       if(j!=h){
         conteo++;
         j=h;
       }
       h=texto.find(vocal_con.substr(k,k+2),i);
     }
     for(i=0;i<conteo;i++){texto.replace(texto.find(vocal_con.substr(k,k+2),i),2,"a");} //tercer for
     break;
    case 2:
    h=0;
    j=0;
    conteo=-1;
    for(i=0;i<texto.length();i++){
      if(j!=h){
        conteo++;
        j=h;
      }
      h=texto.find(vocal_con.substr(k,k),i);
    }
    for(i=0;i<conteo;i++){texto.replace(texto.find(vocal_con.substr(k,k),i),2,"e");}
    break;
    case 4:
    h=0;
    j=0;
    conteo=-1;
    for(i=0;i<texto.length();i++){
      if(j!=h){
        conteo++;
        j=h;
      }
      h=texto.find(vocal_con.substr(k,k-2),i);
    }
    for(i=0;i<conteo;i++){texto.replace(texto.find(vocal_con.substr(k,k-2),i),2,"i");}
    break;
    case 6:
    h=0;
    j=0;
    conteo=-1;
    for(i=0;i<texto.length();i++){
      if(j!=h){
        conteo++;
        j=h;
      }
      h=texto.find(vocal_con.substr(k,k-4),i);
    }
    for(i=0;i<conteo;i++){texto.replace(texto.find(vocal_con.substr(k,k-4),i),2,"o");}
    break;
    case 8:
    h=0;
    j=0;
    conteo=-1;
    for(i=0;i<texto.length();i++){
      if(j!=h){
        conteo++;
        j=h;
      }
      h=texto.find(vocal_con.substr(k,k-4),i);
    }
    for(i=0;i<conteo;i++){texto.replace(texto.find(vocal_con.substr(k,k-4),i),2,"u");}
    break;
  }
}
texto.insert(0,var_prob);


/************ ITEM TRES *************/
/*Pasamos de una cadena string a una cadena de C para
usar la funcion tolower*/
char textoC[texto.length()];

for(i=0;i<texto.length();i++){
  textoC[i]=tolower(texto.at(i)); //tolower pasa de mayusculas a minuculas
}
/************* ITEM CUATRO **********/

int p=0,l=0;
int conteo_num_letras;
char palabra[texto.length()];
while(true){
  //Item 4.1
  conteo_num_letras=0;
  while(textoC[p]!=' '){
    conteo_num_letras++;
    p++;
    if(textoC[p]=='\n'){break;}
  }
  cout << conteo_num_letras << endl;
  p++;

  //Item 4.2

    while(textoC[l]!=' '){
      cout << textoC[l];
      palabra[l]=textoC[l];
      l++;
      if(textoC[l]=='\n'){break;}
    }
    l=p;
    cout << palabra << endl;
  /*Para acabar con el conteo se usa el caracter
  (palabra"espacio"&) al final del texto*/
  if(textoC[p]=='&'){break;}
}





cout << textoC << endl;


  return 0;

}
