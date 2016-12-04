#include "Util.h"
#include <fstream>
#include <sstream>
#include <iostream>


string Util::readFile(const char* path) {
	ifstream input(path, ifstream::in);
	stringstream content;
	if (input) {
		content << input.rdbuf();
	}
	else {
		cout << "FILE FAILED TO LOAD" << endl;
		return "FAILED";
	}
	return content.str();
}