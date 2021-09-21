//
// Created by Sakura on 3/24/2021.
//

#ifndef MATRIX_MATRIXITERATOR_H
#define MATRIX_MATRIXITERATOR_H

#pragma once
#include "Matrix.h"
class MatrixIterator
{
    //DO NOT CHANGE THIS PART
    friend class Matrix;
private:
    const Matrix& matrix;
    int current; //the position of the current element from the elements array from the map
    int line;
    int line_index_start;
    int line_index_end;

    MatrixIterator(const Matrix& m, int l);
public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};


#endif //MATRIX_MATRIXITERATOR_H
