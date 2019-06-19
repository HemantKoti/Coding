//============================================================================
// Name        : main.cpp
// Author      : Hemant Koti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

#include "LeetCode.h"
using namespace std;

int main() {
	ofstream errorLog("Logging/trace.log",
			ios_base::app | ios_base::out);
	try {
		// Write logic here
	} catch (exception & ex) {
		errorLog << ex.what() << endl;
	}
}
