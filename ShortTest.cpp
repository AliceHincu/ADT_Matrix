#include <assert.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
    m.modify(0,0,4);
    m.modify(2,2,59);
    m.modify(3,3,78);
    m.modify(2,1,66);
    m.modify(4,4,1);
}