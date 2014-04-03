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

class area: public circle{
public:
	float setArea(){
		return pi * (d/2) * (d/2);
	}
};


class circumference: public circle{
public:
	void operator=(float diameter);
	float SetCircumference(){
		return pi * d;
	}
};
