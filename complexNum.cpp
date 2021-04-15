#include "complexNum.h"
#include <iostream>

using namespace std;

ComplexNumber::ComplexNumber(float inReal, float inImaginary){
  real = inReal;
  imaginary = inImaginary;
}

float ComplexNumber::getReal() const { return real; }
float ComplexNumber::getImaginary() const { return imaginary; }

void ComplexNumber::setReal(float inReal) { real = inReal; }
void ComplexNumber::setImaginary(float inImaginary) { imaginary = inImaginary; }

void ComplexNumber::print(){
  cout << real << " + " << imaginary << "i" << endl;
}


//Addition with complex numbers is merely addition across each part
ComplexNumber ComplexNumber::operator+(ComplexNumber& rightNumber){
  float outReal = this->real + rightNumber.getReal();
  float outImaginary = this->imaginary + rightNumber.getImaginary();

  return ComplexNumber(outReal, outImaginary);
}

//subtraction with complex numbers is merely subtraction across each part
ComplexNumber ComplexNumber::operator-(ComplexNumber& rightNumber) {
  float outReal = this->real - rightNumber.getReal();
  float outImaginary = this->imaginary - rightNumber.getImaginary();

  return ComplexNumber(outReal, outImaginary);
}

//multiplication with complex numbers is binomial multiplication,
//done here using the FOIL method: First, Outside, Inside, Last.
//I'll explain what I'm doing with the complex numbers (a + bi) and (c + di)
ComplexNumber ComplexNumber::operator*(ComplexNumber& rightNumber){
  //this: (a + bi)   rightNumber: (c + di)
  
  //multiply the first terms of each - the real portions of the complex numbers
  //a * c = ac
  float firstProd = this->real * rightNumber.getReal();

  //multiply the outside terms of each - the real portion of this and the imaginary portion of rightNumber
  //a * di = adi
  float outsideProd = this->real * rightNumber.getImaginary();

  //multiply the inside terms of each - the imaginary portion of this and the real portion of rightNumber
  //bi * c = bci
  float insideProd = this->imaginary * rightNumber.getReal();

  //multiply the last terms of each - the imaginary portions of both complex numbers
  //bi * di = bd(i)^2
  float lastProd = this->imaginary * rightNumber.getImaginary();

  //now what we have is a polynomial that needs to be simplified
  // firstProd + outsideProd + insideProd + lastProd or
  // ac + adi + bci + bd(i)^2
  // the i^2 in the last term can be simplified to -1
  // so now we have ac + adi + bci -bd
  // we can combine like terms, adding the terms with i's together and those without i's together
  // getting (ac - bd) + (ad + bc)i
  // which in and of itself is a new complex number!
  // so looking at the simplified number, what we need to return is a new complex number
  // with (firstProd - lastProd) in the real portion
  // and (insideProd + outsideProd) in the imaginary portion

  return ComplexNumber((firstProd - lastProd), (insideProd + outsideProd)); 
}

//division with complex numbers is done by expressing the division operation as a ratio or fraction,
//then multiplying both the numerator and the denominator by the complex conjugate of the denominator,
//then finally simplifying.
//I'll explain what I'm doing with the complex numbers (a + bi) and (c + di)
ComplexNumber ComplexNumber::operator/(ComplexNumber& rightNumber){
  //this: (a + bi)   rightNumber: (c + di)

  // First, express the division as a ratio or fraction: (a + bi)/(c + di)

  // Then we multiply both the numerator and denominator by the complex conjugate of the denominator
  //   in order to remove any imaginary numbers from the denominator. The complex conjugate will be (c - di) 
  ComplexNumber conjugate(rightNumber.getReal(), -(rightNumber.getImaginary()));

  // ((a + bi)*(c - di))/((c + di)*(c - di))
  // We use the previously defined multiplication operation to multiply and simplify the numerator and denominator
  ComplexNumber numerator = (*this) * conjugate;
  ComplexNumber denominator = (rightNumber) * conjugate; //denominator will only have a real componant. denominator.getImaginary() will return 0 
  
  // We get ((ac - bd) + (ad + bc)i)/(c^2 + d^2)
  // Dividing out, we get ((ac - bd)/(c^2 + d^2)) + ((ad + bc)/(c^2 + d^2))i
  // So we need to divide both the real and imaginary components of numerator by denominator
  // and the complex number returned from that is what we return from the operator/

  return ComplexNumber((numerator.getReal()/denominator.getReal()), (numerator.getImaginary()/denominator.getReal()));
}