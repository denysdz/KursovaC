#pragma once
#include "RealNumber.h"
#include <iostream>

class Matrix : public RealNumber {
private:
    int rows, cols;
    double** data;

public:
    Matrix();
    Matrix(int r, int c);
    ~Matrix();

    double* getMatrixElement(int row, int col);
    void setMatrixElement(int row, int col, int value);

    double norm();

    Matrix& operator=(const Matrix& other);

    friend istream& operator>>(istream& is, Matrix& mat);
    friend ostream& operator<<(ostream& os, const Matrix& mat);
};

