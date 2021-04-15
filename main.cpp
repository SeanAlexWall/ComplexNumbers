#include <iostream>

#include "complexNum.h"

using namespace std;

int main(){
  //(2 + 3i)
  ComplexNumber num1(2, 3);
  //(4 + -6i)
  float real2 = 4, imaginary2 = -6;
  ComplexNumber num2(real2, imaginary2);

  cout << "num1: "; num1.print();
  cout << "num2: "; num2.print();

  //should get 6 + -3i
  ComplexNumber sum = num1 + num2;
  cout << "sum: "; sum.print();

  //should get -2 + 9i
  ComplexNumber diff = num1 - num2;
  cout << "dif: "; diff.print();

  //should get 26 + 0i
  ComplexNumber prod = num1 * num2;
  cout << "prod: "; prod.print();

  //should get appr. -0.1923 + 0.4615i
  ComplexNumber quot = num1 / num2;
  cout << "quot: "; quot.print();
 

  return 0;
}