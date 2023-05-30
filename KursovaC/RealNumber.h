#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class RealNumber {
private:
    double value;

public:
    RealNumber();
    RealNumber(double value);
    RealNumber(const RealNumber& other);
    ~RealNumber();

    void setValue(double newValue);
    double getValue();
    virtual double norm();

    RealNumber operator+(RealNumber& other);
    RealNumber operator-(RealNumber& other);
    RealNumber operator*(RealNumber& other);
    RealNumber operator/(RealNumber& other);
    RealNumber& operator=(RealNumber& other);

    friend istream& operator>>(istream& is, RealNumber& number);
    friend ostream& operator<<(ostream& os, RealNumber& number);
};