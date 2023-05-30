#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realNumber, double imageNumber) : RealNumber(realNumber) {
    this->imageNumber = imageNumber;
}

double ComplexNumber::getImageNumber() {
    return imageNumber;
}

void ComplexNumber::setImageNumber(double image) {
    imageNumber = image;
}

double ComplexNumber::norm() {
    return abs(getValue() + imageNumber);
}

ComplexNumber& ComplexNumber::operator=(ComplexNumber& other) {
    if (this != &other) {
        RealNumber::operator=(other);
        imageNumber = other.imageNumber;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, ComplexNumber& number) {
    double value;
    double imageNumber;
    if (is >> value >> imageNumber) {
        number.setValue(value);
        number.setImageNumber(imageNumber);
    }
    else {
        throw std::invalid_argument("Допустимі тільки дійсні числа.");
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, ComplexNumber& number) {
    if (number.getImageNumber() < 0) {
        os << number.getValue() << number.getImageNumber() << "i";
    }
    else {
        os << number.getValue() << "+" << number.getImageNumber() << "i";
    }
    return os;
}
