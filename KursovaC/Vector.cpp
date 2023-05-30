#include "Vector.h"

Vector::Vector() : RealNumber(), size(0), values(nullptr) {}

Vector::Vector(int n) : RealNumber(), size(n) {
    values = new double[size];
    for (int i = 0; i < size; i++) {
        values[i] = 0.0;
    }
}

Vector::Vector(double arr[], int n) : RealNumber(), size(n) {
    values = new double[size];
    for (int i = 0; i < size; i++) {
        values[i] = arr[i];
    }
}

Vector::~Vector() {
    delete[] values;
}

double Vector::getVectorElement(int index) {
    return values[index];
}

void Vector::setVectorElement(int index, double value) {
    values[index] = value;
}

double Vector::norm() {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i] * values[i];
    }
    return sqrt(sum);
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "{";
    for (int i = 0; i < v.size; i++) {
        os << v.values[i];
        if (i < v.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    std::cout << "Введіть розмір вектора: ";
    int size;
    if (!(is >> size)) {
        throw std::invalid_argument("Допустимі тільки цілі числа!");
    }
    else if (size < 1) {
        throw std::invalid_argument("Розмір має бути більше 0!");
    }
    v.size = size;
    delete[] v.values;
    v.values = new double[v.size];
    std::cout << "Введіть значення вектора: ";
    for (int i = 0; i < v.size; i++) {
        if (!(is >> v.values[i])) {
            throw std::invalid_argument("Допустимі тільки дійсні числа!");
        }
    }
    return is;
}
