#include <iostream>
using namespace std;


class circle{
protected:
	float pi;
	float d;

public:
	void setCircle();
	void set_values (float diameter, float pi5)
	{
		d = diameter;
		pi = pi5;
	}
};
