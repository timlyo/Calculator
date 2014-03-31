#include <iostream>
#include "modular.h"

std::string modular::calculation(int value1, int value2)
{
    answer = value1 % value2;
    return answer;
}

