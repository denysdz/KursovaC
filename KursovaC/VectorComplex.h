#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "ComplexNumber.h"
#include "VectorCustomIterator.h"

class VectorComplex {
private:
    vector<ComplexNumber> data;

public:
    VectorComplex();

    VectorComplex(vector<ComplexNumber> v);

    void push_back(ComplexNumber c);

    VectorComplex& operator=(const VectorComplex& other);

    ComplexNumber getMaxModule();

    friend istream& operator>>(istream& is, VectorComplex& cmpVector);

    friend ostream& operator<<(std::ostream& os, VectorComplex& cmpVector);
};
