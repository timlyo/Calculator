#include <string>
#include <iostream>

#include "number.h"

using std::string;

//basic number
char& BasicNumber::operator[](int position){
	return value[position];
}

char& BasicNumber::operator[](unsigned int position){
	return value[position];
}

void BasicNumber::operator=(std::string newValue){
	value = newValue;
}

BasicNumber::BasicNumber(unsigned int size, char character){
	value.resize(size);
	for(unsigned int i = 0; i < value.size(); i++)
		value[i] = character;
}

BasicNumber::BasicNumber(std::string text){
	value = text;
}

BasicNumber::BasicNumber(const char *text){
	value = *text;
}

void BasicNumber::resize(int newSize){
	value.resize(newSize);
}

unsigned int BasicNumber::size(){
	return value.size();
}

std::string BasicNumber::toString(){
	return value;
}

BinaryNum& BinaryNum::fromOther(std::string input){
	BinaryNum temp(input);
	return temp;
}


//Binary Number
bool BinaryNum::isValid(){
	for(unsigned int i = 0; i < value.size(); i++){
		if(value[i] != '0' and value[i] != '1'){
			return false;
		}
	}
	return true;
}

void BinaryNum::padBinary(const unsigned int characters){
	if(value.size() > characters)
		return;
	string newNumber;
	newNumber.resize(characters);
	int sizeChange = characters - value.size();
	for(unsigned int i = 0; i < value.size(); i++){
		newNumber[i+sizeChange] = value[i];
	}
	for(unsigned int i = 0; i < newNumber.size()-value.size(); i++){
		value[i] = '0';
	}
	value = newNumber;
}

void BinaryNum::padBinary(BinaryNum *number){
	if(value.size() > number->size())
		number->padBinary(value.size());
	else if(number->size() > value.size())
		number->padBinary(value.size());
}
