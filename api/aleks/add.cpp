#include "add.h"

string Add::Input (string a, string b, char operation)
{
	switch (operation)
	{
		case '+': result = stod(a)+stod(b); break;
		case '-': result = stod(a)-stod(b); break;
		case '*': result = stod(a)*stod(b); break;
		case '/': result = stod(a)/stod(b); break;

		default: cout << "Insert number then either *,-,+, or / followed by another number \n\n";

	}
	return to_string(result);
}
