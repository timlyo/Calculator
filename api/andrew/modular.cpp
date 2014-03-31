#include <iostream>
#include <string>
#include "modular.h"

std::string Modular::calculation(int value1, int value2){
	int answer = value1 % value2;
	return std::to_string(answer);
}

