#include <string>

#include "inversion.h"

using std::string;

string inversionClass::inversion(string binary){
	string tempString;
	tempString.erase();

	for (int x = binary.size()-1; x >=0; x--)
    {
		tempString.push_back(binary[x]);
    }
	return tempString;
}
