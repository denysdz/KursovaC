#include "Matrix.h"

Matrix::Matrix() {
    rows = cols = 0;
    data = nullptr;
}

Matrix::Matrix(int r, int c) : RealNumber(), rows(r), cols(c) {
    data = new double* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

double* Matrix::getMatrixElement(int row, int col) {
    return &data[row][col];
}

void Matrix::setMatrixElement(int row, int col, int value) {
    data[row][col] = value;
}

double Matrix::norm() {
    double maxNorm = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double absValue = abs(data[i][j]);
            if (absValue > maxNorm) {
                maxNorm = absValue;
            }
        }
    }
    return maxNorm;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new double* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

istream& operator>>(istream& is, Matrix& mat) {
    cout << "Введіть розмір матриці (рядки, стовпці): ";
    int rows, cols;
    if (!(is >> rows)) {
        throw invalid_argument("Допустимі тільки цілі числа!");
    }
    else if (!(is >> cols)) {
        throw invalid_argument("Допустимі тільки цілі числа!");
    }
    else if (rows <= 0 || cols <= 0) {
        throw invalid_argument("Розмір має бути більше 0!");
    }
    mat = Matrix(rows, cols);
    cout << "Введіть елементи матриці: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(is >> mat.data[i][j])) {
                throw invalid_argument("Допустимі тільки дійсні числа!");
            }
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            os << mat.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

