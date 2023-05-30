#pragma once
#include "RealNumber.h"
#include <iostream>

class ComplexNumber : public RealNumber {
private:
    double imageNumber;

public:
    ComplexNumber(double realNumber = 0.0, double imageNumber = 0.0);
    double getImageNumber();
    void setImageNumber(double image);
    double norm();

    ComplexNumber& operator=(ComplexNumber& other);

    friend std::istream& operator>>(std::istream& is, ComplexNumber& number);
    friend std::ostream& operator<<(std::ostream& os, ComplexNumber& number);
};
