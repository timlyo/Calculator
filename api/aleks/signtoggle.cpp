#include "signtoggle.h"

string SignToggle::InputSignToggle (string number, string sign)
{
	if (sign.compare("M+") == 0)
	{
		sa = std::stod(number)*-1;
		return std::to_string(sa);
	}
	else
	{
		sa = std::stod(number)*-1;
		return std::to_string(sa);
	}
}
