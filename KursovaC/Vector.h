#pragma once
#include <iostream>
#include <cmath>
#include "RealNumber.h"

class Vector : public RealNumber {
private:
    int size;
    double* values;

public:
    Vector();
    Vector(int n);
    Vector(double arr[], int n);
    ~Vector();

    double getVectorElement(int index);
    void setVectorElement(int index, double value);

    double norm();

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);
};

