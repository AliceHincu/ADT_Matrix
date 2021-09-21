//
// Created by Sakura on 3/24/2021.
//

#include "Matrix.h"
#include "MatrixIterator.h"
#include <exception>
#include <cstdio>

using namespace std;


MatrixIterator::MatrixIterator(const Matrix& m, int l) : matrix(m), line(l)
{
    this->line_index_start = 0;
    this->line_index_end = this->matrix.size;
    int found = 1;
    int found_end = 1;
    for(int index=0; index<this->matrix.size; index++){
        if (this->matrix.elements[index].first.first == this->line && found == 1){
            this->line_index_start = index;
            found = 0;
        }
        else{
            if (this->matrix.elements[index].first.first != this->line && this->matrix.elements[index-1].first.first == this->line && found_end==1){
                this->line_index_end = index;
                found_end = 0;
                break;
            }

        }
    }

    this->current = this->line_index_start;
}//Best case: Theta(nrCols)..Worst case: Theta (size) => O(size) < O(n)


void MatrixIterator::first() {
    this->current = this->line_index_start;
}//Theta(1)


void MatrixIterator::next() {
    if (!valid()) throw exception();
    else this->current++;
}//Theta(1)


TElem MatrixIterator::getCurrent(){
    if (!valid()) throw exception();
    return this->matrix.elements[this->current].second;
}//Theta(1)


bool MatrixIterator::valid() const {

    if (this->current >= this->line_index_end) return false;
    return true;
}//Theta(1)




