#include <string>
#include <iostream>
#include <cmath>

#include "bitwise.h"

using std::string;

string Bitwise::shiftLeft(BinaryNum number, const unsigned int places){
	number.resize(number.size() + places);
	for(unsigned int i = number.size(); i > (number.size() - places); i--){
		number[i-1] = '0';
	}
	return number.toString();
}

string Bitwise::shiftRight(BinaryNum number,const unsigned int places){
	if(places > number.size())
		return "e";
	number.resize(number.size()-places);
	return number.toString();
}

string Bitwise::rotateLeft(BinaryNum number, const unsigned int places){
	BinaryNum tempString(number.size(), '0');
	for(unsigned int i = 0; i < number.size(); i++)
		tempString[(i - places)%number.size()] = number[i] ;
	return tempString.toString();
}

string Bitwise::rotateRight(BinaryNum number, const unsigned int places){
	BinaryNum tempString(number.size() ,'0');
	for(unsigned int i = 0; i < number.size(); i++)
		tempString[(i + places)%number.size()] = number[i];
	return tempString.toString();
}

string Bitwise::set(BinaryNum number, char bit, const unsigned int place){
	number[place] = bit;
	return number.toString();
}

string Bitwise::clear(BinaryNum number, const unsigned int place){
	number[place] = '0';
	return number.toString();
}
