#include "RealNumber.h"

RealNumber::RealNumber() : value(0) {}

RealNumber::RealNumber(double value) : value(value) {}

RealNumber::RealNumber(const RealNumber& other) {
    value = other.value;
}

RealNumber::~RealNumber() {}

void RealNumber::setValue(double newValue) {
    value = newValue;
}

double RealNumber::getValue() {
    return value;
}

double RealNumber::norm() {
    return abs(value);
}

RealNumber RealNumber::operator+(RealNumber& other) {
    return RealNumber(value + other.value);
}

RealNumber RealNumber::operator-(RealNumber& other) {
    return RealNumber(value - other.value);
}

RealNumber RealNumber::operator*(RealNumber& other) {
    return RealNumber(value * other.value);
}

RealNumber RealNumber::operator/(RealNumber& other) {
    return RealNumber(value / other.value);
}

RealNumber& RealNumber::operator=(RealNumber& other) {
    value = other.value;
    return *this;
}

istream& operator>>(istream& is, RealNumber& number) {
    double value;
    if (is >> value) {
        number.setValue(value);
    }
    else {
        throw invalid_argument("Допустимі тільки дійсні числа.");
    }
    return is;
}

ostream& operator<<(ostream& os, RealNumber& number) {
    os << number.getValue();
    return os;
}
