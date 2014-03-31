#include <string>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;

#ifndef STRINGS_H
#define STRINGS_H
namespace strings{
	/**compare how similar two strings are and returns the result as float between 0 and 1*/
	float compareStrings(string string1, string string2);
	/**sort a string and return the sorted string*/
	string sortString(string stringy);
	/**removes duplicate characters from a string*/
	string removeDupes(string string, bool sorted=false);
	/**Finds a string inside of an array or a vector and returns it's position*/
	int searchArray(vector<string> array, string input);
	int searchArray(string array[], string input);
	/**returns 1 if the input is a number*/
	bool isNumber(string input);
	/**returns 1 if the input is a alphabetic character*/
	bool isAlphabetic(string input);
}//end of namespace
#endif
