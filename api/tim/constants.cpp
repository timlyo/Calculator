#include "constants.h"

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::string;
using std::make_pair;

Constants::Constants(){
	constantsList.push_back(make_pair("c","299792458"));
	constantsList.push_back(make_pair("pi","3.141592654"));
	constantsList.push_back(make_pair("tau","6.283185307"));
}

bool Constants::isConstant(string constant){
	for(unsigned int i = 0; i < constantsList.size(); i++){
		if(constantsList[i].first.compare(constant) == 0)
			return true;
	}
	return false;
}

void Constants::replaceValue(std::string *constant){
	for(int i = 0; i < constantsList.size(); i++){
		if(constant->compare(constantsList[i].first) == 0){
			*constant = constantsList[i].second;
		}
	}
}
