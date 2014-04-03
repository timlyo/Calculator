#include <string>

using std::string;

#ifndef NUMBER_H
#define NUMBER_H
class BasicNumber{
protected:
	string value;
public:
	explicit BasicNumber();
	explicit BasicNumber(string text);
	explicit BasicNumber(const char* text);
	explicit BasicNumber(unsigned int size, char character);

	virtual bool isValid()=0;
	void resize(int newSize);
	unsigned int size();
	string toString();

	//operators
	char& operator[](signed int position);
	char& operator[](unsigned int position);
	void  operator= (string newValue);
};

class BinaryNum: public BasicNumber{
public:
	/**inherited constructor from base class*/
	using BasicNumber::BasicNumber;

	/**convert other types to BasicNumber*/
	static BinaryNum& fromOther(string input);
	static BinaryNum& fromOther(char input);

	/**Checks if the number is a valid binary number(all 1's and 0's)*/
	bool isValid();
	/**Adds 0's to the front of a string to pad it out to the number
	 * or the size of the second argument*/
	void padBinary(const unsigned int characters);
	void padBinary(BinaryNum *number);
};
#endif
