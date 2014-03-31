#include <cmath>
#include <string>

#include "power.h"

using namespace std;

string Power::InputPower (string pa, string pb, char operationPower)
{
	switch (operationPower)
	{
		case '^' : result = pow(stod(pa),stoi(pb)); break;

		default : cout <<"Insert number a then ^ followed by number b \n\n";
	}
	return to_string(result);
}
