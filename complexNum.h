#ifndef COMPLEX_NUM_H
#define COMPLEX_NUM_H

#include <string>

using namespace std;

class ComplexNumber{
  private:
    float real;
    float imaginary;
  public:
    ComplexNumber(float inReal, float inImaginary);

    float getReal() const;
    float getImaginary() const;
    void setReal(float inReal);
    void setImaginary(float inImaginary);
    void print();

    ComplexNumber operator+(ComplexNumber& rightNumber);
    ComplexNumber operator-(ComplexNumber& rightNumber);
    ComplexNumber operator*(ComplexNumber& rightNumber);
    ComplexNumber operator/(ComplexNumber& rightNumber);   
};
#endif