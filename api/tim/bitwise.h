#include <string>

using std::string;

#include "number.h"

#ifndef BITWISE_H
#define BITWISE_H
class Bitwise{
public:
	string shiftLeft(BinaryNum number, const unsigned int places);
	string shiftRight(BinaryNum number, const unsigned int places);
	string rotateLeft(BinaryNum number, const unsigned int places);
	string rotateRight(BinaryNum number, const unsigned int places);
	string set(BinaryNum number, char bit, const unsigned int place);
	string clear(BinaryNum number, const unsigned int place);
};
#endif
