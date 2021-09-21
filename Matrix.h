#pragma once
#include <utility>

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

typedef std::pair<std::pair<TElem, int>, bool> Element;  //(element+index)+existence
typedef std::pair<int, int> MatrixIndex;  //index of line+index of col
typedef std::pair<MatrixIndex, TElem > Triple;

class MatrixIterator;

class Matrix {

    friend class MatrixIterator;

private:
	//TODO - Representation
	int lines; //nr of lines
	int cols; // nr of cols
	Triple* elements;
	int size;
	int capacity;

	// return the value of the element, the element's index and if it was found or not
	Element linearSearch(MatrixIndex) const;

	// resize the array
    void resize(int val);

    // inserts an element into the array.
    // expands the capacity if the array is full
    // check if the position is good
    void insertElement(int poz, Triple el);

    // inserts an element into the array.
    // expands the capacity if the array is full
    // check if the position is good
    void removeElement(int poz);

    // destructor
    //~Matrix();

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

    //returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	// creates an iterator over all the elements of the Matrix on a given line (no matter if they are NULL_TELEM or not)
	// throws exception if line is not a valid line
	MatrixIterator iterator(int line) const;

};
