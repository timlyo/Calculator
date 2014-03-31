#include "circleEquation.h"


class area: public circle{
public:
	float setArea(){
		return pi * (d/2) * (d/2);
	}
};


class circumference: public circle{
public:
	float SetCircumference(){
		return pi * d;
	}
};
