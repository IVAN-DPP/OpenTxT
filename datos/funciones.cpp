#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace OpenTxT{

/*----------- Operaciones ----------*/

//Calculo del factorial de un numero n
  int factorial_num(int number){
    int n=1;                      //Empieza en 1 para que el factorial de cero sea 1
    for(int i=1;i<=number;i++)    //Se realiza el bucle para el factorial
      n*=i;
    return n;
  }

/*----------- Números --------------*/

  double pi(int decimal){
    cout << setprecision(decimal);         //Número de decimales en PI
    return asin(1)*2;
  }

  double pi(){
    cout << setprecision(6);              //Número de decimales en PI por defecto
    return asin(1)*2;
  }

  double exp(double x,int order){                  //Orden n de la serie de taylor de exp(x)
    double expo;
    for(int i=0;i<=order;i++)
      expo+=pow(x,i)/factorial_num(i);
    return expo;
  }

  double exp(double x){                           //Orden 6 de la serie de taylor de exp(x)
    double expo;
    for(int i=0;i<=6;i++)
      expo+=pow(x,i)/factorial_num(i);
    return expo;
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
      chi2=pow(x,k*0.5-1)*pow(exp(1,10),-x*0.5)/(pow(2,k*0.5)*gamma_function(double(k)/double(2)));
    return chi2;
  }

/*------------ Metodos para calcular integrales ------------------*/

  double (*function)(double,int);          //Esta función nos permite definir cualquier función para calcular el área bajo la curva
  double (*Function)(double);

  double below_rectangle(double a,double b,int k,int n){  //Limite inferior, limite superior, grado de libertad, número de intervalos
    double A=0,dx;
    dx=(b-a)/n;
    for(int i=0;i<n;i++)
      A+=(*function)(a+i*dx,k)*dx;  //Se pone la función f(a+i*dx,k) se puede cambiar por cualquier función de tipo (double,int)
    
    return A;
  }

  double below_rectangle(double a,double b,int n){         //Limite inferior, limite superior, número de intervalos
    double A=0,dx;
    dx=(b-a)/n;
    for(int i=0;i<n;i++)
      A+=(*Function)(a+i*dx)*dx;  //Se pone la función f(a+i*dx) se puede cambiar por cualquier función de tipo (double)
    
    return A;
  }


  class Statistics{
    
  private:
    vector< vector<int> > data;
    
    
  public:
    Statistics();
    Statistics(vector< vector<int> >);
    vector< vector<int> > marginal_frequency();
    int total();
    void chi2_test(double);
  };
  Statistics::Statistics(){}
  Statistics::Statistics(vector< vector<int> > Data){
    for(int i=0;i<Data.size();i++)
      data.push_back(Data[i]);
  }
  vector< vector<int> > Statistics::marginal_frequency(){
    int frequency;
    vector<int> xfrequency;
    vector<int> yfrequency;
    vector< vector<int> > frequency_matrix;

    //Suma sobre cada fila
    for(int i=0;i<data.size();i++){
      frequency=0;                                //Se inicializa en cero siempre para no guardar el resultado de la suma anterior
      for(int j=0;j<data[i].size();j++)
	frequency+=data[i][j];
      xfrequency.push_back(frequency);            //Se guarda el resultado en un vector
    }
    frequency_matrix.push_back(xfrequency);       //Se guarda en la matriz
    //Suma sobre cada columna
    for(int j=0;j<data[0].size();j++){
      frequency=0;
      for(int i=0;i<data.size();i++)  
	frequency+=data[i][j];
      yfrequency.push_back(frequency);
    }
    frequency_matrix.push_back(yfrequency);

    //La primera fila representa la suma sobre las columnas N(i.) y la segunda sobre las columnas N(.j)
    return frequency_matrix;
  }

  int Statistics::total(){
    vector<vector<int>> frequency=marginal_frequency();
    int total=0;
    for(int i=0;i<frequency[0].size();i++)
      total+=frequency[0][i];
    return total;
  }

  
  /*---- Análisis de Correspondencias -----------*/
  void Statistics::chi2_test(double x){
    function=chi2_function;
    double probability = below_rectangle(0,x,1,10000);
    vector<vector<int>> marginal=marginal_frequency();
    int tot=total();
    double chi2_exp=0;
    for(int i=0;i<data.size();i++)
      for(int j=0;j<data[i].size();j++)
	chi2_exp+=pow(double(data[i][j])/double(marginal[1][j])-double(marginal[0][i])/double(tot),2)*tot*marginal[1][j]/marginal[0][i];
    cout <<chi2_exp <<"    " << probability<<endl;
    if(chi2_exp<probability)
      cout << "Las dos variables son independientes bajo " << x << endl;
    else
      cout << "Las dos variables son dependientes bajo " << x << endl;
    cout << (data.size()-1)*(data[0].size()-1) << endl;
  }
}
#include "datos.h"

int main(){

  //cout << factorial_num(0) << endl;
  //cout << pi() << endl;
  //cout << gamma_function(double(9)/double(2)) << endl;
  //cout << chi2_function(0.001,1) << endl;
  OpenTxT::function=OpenTxT::chi2_function;                               //Se define la función a la cual se quire sacar el area bajo la curva con parametros (double,int)
  cout << OpenTxT::below_rectangle(0,60.48,44,10000) << endl;
  
  //cout << (*function)(0.001,1) << endl;
  /*
  OpenTxT::Datos a("prb.txt");
  a.load_text();
  a.save_file1("DATOS.txt");
  OpenTxT::Statistics b(a.get_frequency_matrix1());
  vector<vector<int>> marginal=b.marginal_frequency();
  b.total();
  b.chi2_test(0.2);
  */
  return 0;
}
