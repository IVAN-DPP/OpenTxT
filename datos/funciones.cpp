#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

/*----------- Números --------------*/

double pi(int decimal){
  cout << setprecision(decimal);         //Número de decimales en PI
  return asin(1)*2;
}
/*----------- Operaciones ----------*/

//Calculo del factorial de un numero n
int factorial_num(int number){
  int n=1;                      //Empieza en 1 para que el factorial de cero sea 1
  for(int i=1;i<=number;i++)    //Se realiza el bucle para el factorial
    n*=i;
  return n;
}

/*------------ Funciones ------------*/

//En este momento la función gamma solo calcula valores de tipo entero como 1,2,3,4,5,.... y numeros que se dividan entre 2 1/2,3/2,5/2,...

double gamma_function(double alpha){    
  double gamma=0;                                
  int numerator=1, denominator;               //Numerador y denominador de la fracción que se realiza si el número a calcular no es divisible entre 2
  if((alpha-int(alpha))==0)                   //Si alpha es un número entero entonces esta diferencia da cero por lo que se calcula el factorial
    gamma=factorial_num(int(alpha)-1);    
  else{                                       //Si alpha no es divisible entre cero entonces se procede a calcular de la otra manera
    denominator=pow(2,alpha-0.5);
    for(int i=1;i<alpha-0.5;i++)
      numerator*=2*i+1;

    gamma=double(numerator)*sqrt(pi(6))/double(denominator);
  }
  return gamma;
}

double chi2_function(double x,int k){
  double chi2;
  if(x<=0)
    chi2=0;
  else
    chi2=pow(x,k*0.5-1)*pow(2.71828,-x*0.5)/(pow(2,k*0.5)*gamma_function(double(k)/double(2)));
  return chi2;
}
int main(){

  cout << factorial_num(0) << endl;
  cout << pi(2) << endl;
  cout << gamma_function(double(9)/double(2)) << endl;
  cout << chi2_function(0.5,1) << endl;

  return 0;
}
