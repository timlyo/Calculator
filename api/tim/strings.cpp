#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

#include "strings.h"
namespace strings{
	float compareStrings(string string1, string string2){
		string1 = removeDupes(string1);
		string2 = removeDupes(string2);
		
		int numSimilarChars = 0;
		for(unsigned int i = 0; i < string1.size(); i++){
			for(unsigned int j = 0; j < string2.size(); j++){
				if(string1.at(i) == string2.at(j))
					numSimilarChars++;
			}
		} 
		
		float averageCharacterNum = 0.5*(string1.size()+string2.size());
		return numSimilarChars/averageCharacterNum;
	}

	string sortString(string stringy){
		std::sort(stringy.begin(), stringy.end());
		return stringy;
	}

	string removeDupes(string stringy, bool sorted){
		if(sorted == false)
			stringy = sortString(stringy);
		for(unsigned int i = 1; i < stringy.size(); i++){
			if(stringy.at(i) == stringy.at(i-1)){
				stringy.erase(stringy.begin()+i);
				i--;
			}
		}
		return stringy;
	}

	int searchArray(vector<string> array, string input){
		for(unsigned int i = 0; i < array.size(); i++){
			if(input.compare(array.at(i)) == 0){
				return i;
			}
		}
		return -1;
	}
		
	int searchArray(string array[], string input){
		unsigned int arraySize = sizeof(array)/sizeof(array[0]);
		for(unsigned int i = 0; i < arraySize; i++){
			if(input.compare(array[i]) == 0)
				return i;
		}
		return -1;
	}
	
	bool isNumber(string input){
		if(isdigit(input.front()))
			return 1;
		else
			return 0;
	}

	bool isAlphabetic(std::string input){
		if(isalpha(input.front()))
			return 1;
		else
			return 0;
	}
}
