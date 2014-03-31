#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::string;
using std::pair;

class Constants{
	vector< pair<string, string> > constantsList;
public:
	Constants();
	/**checks to see if the constant exists within the constantsList*/
	bool isConstant(string constant);
	/**replaces string passed by reference with it's numerical value*/
	void replaceValue(string *constant);
};

#endif // CONSTANTS_H
