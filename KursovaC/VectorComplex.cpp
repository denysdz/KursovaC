#include "VectorComplex.h"

VectorComplex::VectorComplex() {}

VectorComplex::VectorComplex(vector<ComplexNumber> v) : data(v) {}

void VectorComplex::push_back(ComplexNumber c) {
    data.push_back(c);
}

VectorComplex& VectorComplex::operator=(const VectorComplex& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

ComplexNumber VectorComplex::getMaxModule() {
    ComplexNumber max = data[0];
    for (auto& curren : data) {
        if (curren.norm() > max.norm()) {
            max = curren;
        }
    }
    return max;
}

istream& operator>>(istream& is, VectorComplex& cmpVector) {
    cout << "Введіть розмір вектора комплексних чисел: ";
    int size;
    if (!(is >> size)) {
        throw invalid_argument("Недійсний ввід для розміру вектора!");
    }
    else if (size < 1) {
        throw invalid_argument("Розмір не може бути меншим або дорівнювати 0!");
    }
    vector<ComplexNumber> v{};
    cmpVector = VectorComplex(v);
    for (int i = 0; i < size; i++) {
        ComplexNumber cmpNum(0);
        cout << "Уведіть дійсну та уявну частини комплексного числа під номером #" << i + 1 << ": ";
        if (is >> cmpNum)
            cmpVector.push_back(cmpNum);
    }
    return is;
}

ostream& operator<<(std::ostream& os, VectorComplex& cmpVector) {
    os << "[";
    VectorCustomIterator it(cmpVector.data.begin(), cmpVector.data.end());
    while (it != VectorCustomIterator(cmpVector.data.end(), cmpVector.data.end())) {
        os << *it;
        if (++it != VectorCustomIterator(cmpVector.data.end(), cmpVector.data.end())) {
            os << ", ";
        }
    }
    os << "]" << endl;
    return os;
}
