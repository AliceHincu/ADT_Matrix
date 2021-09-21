#include "Matrix.h"
#include "MatrixIterator.h"
#include <exception>
// #include <iostream>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
    this->lines = nrLines;
    this->cols = nrCols;
    this->elements = new Triple [5];
    this->size = 0;
    this->capacity = 5;
}

/*
Matrix::~Matrix(){
    delete [] this->elements;
}*/

int Matrix::nrLines() const {
	return this->lines;
} //Theta(1)


int Matrix::nrColumns() const {
	return this->cols;
} //Theta(1)


//returns the element from line i and column j (indexing starts from 0)
TElem Matrix::element(int i, int j) const {
	if (i < 0  ||  i > this->lines  ||  j < 0 ||  j > this->cols)
	    throw exception();
	else{
	    Element el= linearSearch(make_pair(i, j));
	    return el.first.first;
	}
} //Best case: Theta(1)..Worst case: Theta(size) => Complexity: O(size) < O(n)


//modifies the value from line i and column j
TElem Matrix::modify(int i, int j, TElem e) {
    // if the condition it's not ok
    if (i < 0  ||  i > this->lines  ||  j < 0 ||  j > this->cols)
        throw exception();
    else{
        Element el = linearSearch(make_pair(i,j));
        int index = el.first.second;
        TElem current_value = el.first.first;

        //current_value = 0 and new_Value = 0 => do nothing
        if (current_value == 0 and e == 0)
            return current_value;
        //current_value = 0 and new_Value != 0 => insert in the data structure
        else if (current_value == 0 and e != 0)
            insertElement(index, make_pair(make_pair(i, j),e));
        //current_value != 0 and new_Value = 0 => remove from the data structure
        else if (current_value != 0 and e == 0)
            removeElement(index);
        //current_value != 0 and new_Value != 0 => just modify
        else if (current_value != 0 and e != 0)
            this->elements[index].second = e;
        return current_value;
    }
}//Best case: Theta(1)..Worst case: Theta(size)*Theta(size-poz+1) -> Total complexity:  O(size*(size-poz+1)) < O(n^2)


void Matrix::resize(int val){
    auto* new_array = new Triple [val];
    for(int i = 0; i < this->size;i++)
        new_array[i] = this->elements[i];
    delete[] this->elements;
    this->elements = new_array;
    this->capacity=val;
}// Best case = Worst case = Theta(size) => Complexity: O(size) < O(n)


void Matrix::insertElement(int poz, Triple el){
    //if it's full, expand it
    if(this->size == this->capacity)
        resize(this->capacity*2);
    if (poz<0 || poz > this->size)
        throw exception();
    for(int i = this->size; i >= poz; i--)
        this->elements[i] = this->elements[i-1];
    this->size++;
    this->elements[poz] = el;
}//Best case: Theta(1)...Worst case: Theta(size-poz+1) =>Complexity: O(size-poz+1) < O(n)

void Matrix::removeElement(int poz){
    //if it's half full, shorten it
    if(this->size == this->capacity/2)
        resize(this->capacity/4);
    if (poz<0 || poz > this->size)
        throw exception();
    for(int i = poz; i <= this->size; i++)
        this->elements[i] = this->elements[i+1];
    this->size--;
}//Best case: Theta(1)...Worst case: Theta(size-poz+1)*Theta(n) =>Complexity: O(n*(size-poz+1)) < O(n)


// return the value of the element, the element's index and if it was found or not
Element Matrix::linearSearch(MatrixIndex indexes) const{
    int index = 0;
    while(index < this->size){
        if (this->elements[index].first == indexes)
            return make_pair(make_pair(this->elements[index].second,index), true);
        if (this->elements[index].first > indexes)
            return make_pair(make_pair(0,index), false);
        index++;
    }
    return make_pair(make_pair(0, index), false);
}//Best case: Theta(1)..Worst case: Theta(size) => Complexity: O(size) < O(n)

MatrixIterator Matrix::iterator(int line) const {
    return MatrixIterator(*this, line);
}//Theta(1)


