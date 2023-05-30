#ifndef VECTOR_CUSTOM_ITERATOR_H
#define VECTOR_CUSTOM_ITERATOR_H

#include "VectorComplex.h"

class VectorCustomIterator {
private:
    vector<ComplexNumber>::iterator beginIt;
    vector<ComplexNumber>::iterator endIt;
    vector<ComplexNumber>::iterator it;

public:
    VectorCustomIterator(vector<ComplexNumber>::iterator beginIt, vector<ComplexNumber>::iterator endIt);

    VectorCustomIterator& operator++();
    VectorCustomIterator& operator--();
    bool operator!=(const VectorCustomIterator& other) const;
    ComplexNumber& operator*();
};

#endif