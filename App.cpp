
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;


int main() {
	testAll();
	//testAllExtended();
	cout << "Test End" << endl;
	system("read -p 'Press Enter to continue...' var");
}