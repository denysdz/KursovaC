#include "VectorCustomIterator.h"

VectorCustomIterator::VectorCustomIterator(vector<ComplexNumber>::iterator beginIt, vector<ComplexNumber>::iterator endIt)
    : beginIt(beginIt), endIt(endIt), it(beginIt) {}

VectorCustomIterator& VectorCustomIterator::operator++() {
    if (it == endIt) {
        throw out_of_range("Iterator out of bounds");
    }
    ++it;
    return *this;
}

VectorCustomIterator& VectorCustomIterator::operator--() {
    if (it == beginIt) {
        throw out_of_range("Iterator out of bounds");
    }
    --it;
    return *this;
}

bool VectorCustomIterator::operator!=(const VectorCustomIterator& other) const {
    return it != other.it;
}

ComplexNumber& VectorCustomIterator::operator*() {
    return *it;
}