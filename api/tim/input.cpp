#include <iostream>
#include <string>
#include <vector>

#include "input.h"
#include "strings.h"

#include "number.h"

#include "api/josh/inversion.h"
#include "api/aleks/add.h"

using std::vector;
using std::string;

void Input::replaceWords(vector<string> *input, vector<string> wordArray, string character){
	for(unsigned int i = 0; i < input->size(); i++){
		for(unsigned int j = 0; j < wordArray.size(); j++){
			if(strings::compareStrings(input->at(i),wordArray.at(j)) > acuracy){
				input->at(i) = character;
			}
		}
	}
}

vector<string> Input::vectoriseInput(string input){
	//remove spaces
	for(unsigned int i = 0; i < input.size(); i++){
		if(input[i] == ' '){
			input.erase(input.begin()+i);
			i--;
		}
	}

	vector<string> output;
	string tempString;

	for(unsigned int i = 0; i < input.size(); i++){
		if(isdigit(input.at(i))){ //pull out numbers
			getNumber(input, &tempString, i);
			std::cout << tempString << std::endl;
			i += tempString.size() - 1;
		}else if(isalpha(input.at(i))){//pull out words
			getWord(input, &tempString, i);
			i+= tempString.size() - 1;
		}else{//pull out character
			tempString.push_back(input.at(i));
		}
		if(!tempString.empty())
			output.push_back(tempString);
		tempString.clear();
	}

	return output;
}

vector<string> Input::formatInput(vector<string> input){
	for(unsigned int i = 0; i < input.size(); i++){
		//Removing short words
		for(unsigned int j = 0; j < shortWords.size(); j++){
			if(strings::compareStrings(input.at(i),(shortWords.at(j))) > 0.7){
				input.erase(input.begin() + i);
				i--;
			}
		}
		//insert constants
		if(constants.isConstant(input[i]))
			constants.replaceValue(&input[i]);
	}
	replaceWords(&input, plus,	"+");
	replaceWords(&input, minus,	"-");
	replaceWords(&input, divide,"/");
	replaceWords(&input, times,	"*");
	replaceWords(&input, power,	"^");
	replaceWords(&input, invert,"&");
	
	return input;
}
bool Input::valid(std::string input){
	bool validToggle = false;
	if(strings::isNumber(input) == 1){
		validToggle = true;
	}

	for(unsigned int j = 0;j < characters.size();j++){
		if(input.compare(characters[j]) == 0)
			validToggle = true;
	}

	if(validToggle)
		return 1;
	else
		return 0;
}

bool Input::valid(vector<std::string> inputList){
	bool validToggle;
	for(unsigned int i = 0; i < inputList.size(); i++){
		validToggle = false;
		if(strings::isNumber(inputList.at(i)) == 1){
			validToggle = true;
		}

		for(unsigned int j = 0;j < characters.size();j++){
			if(inputList[i].compare(characters[j]) == 0)
				validToggle = true;
		}

	}
	if(validToggle)
		return 1;
	else
		return 0;
}

int Input::getPriority(std::string input){
	for(unsigned int i = 0; i < operators.size(); i++){
		if(operators.at(i).compare(input) == 0){
			return i;
		}
	}
	return -1;
}

void Input::getNumber(string input, string *number, unsigned int position){
	if(position < input.size()){
		if(isdigit(input.at(position))){
			number->push_back(input.at(position));
			getNumber(input, number, ++position);
		}
	}
}

void Input::getWord(std::string input, std::string *word, unsigned int position){
	if(position < input.size()){
		if(isalpha(input.at(position))){
			word->push_back(input.at(position));
			getWord(input, word, ++position);
		}
	}
}

string Input::calculate(vector<string> input){
	int maxIterations = input.size()*2;

	while(input.size() > 1){
		std::cout << "Calculation" << maxIterations << ": ";
		for(unsigned int i = 0; i < input.size(); i++)
			std::cout << input.at(i) << ",";
		std::cout << std::endl;


		if(maxIterations <= 0)
			break;
		else
			maxIterations--;

		input = validateInput(input);

		int highestOpPos = getHighestPriorityOp(input);

		if(highestOpPos < 0)
			break;

		//prefix operators
		if(highestOpPos + 1 == input.size())
			break;
		if(input.at(highestOpPos).compare("&") == 0){
			input.at(highestOpPos) = inversion.inversion(input.at(highestOpPos+1));
			input.erase(input.begin() + highestOpPos+1);
		}

		if(highestOpPos < 1)
			break;

		//postfix operators
		/*if(input.at(highestOperatorPos).compare("!") == 0){
			//factorial
		}*/
		//check for segFaults
		else if(highestOpPos + 1 == input.size())
			break;

		//infix operators
		else if(input.at(highestOpPos).compare("+") == 0){
			input.at(highestOpPos-1) = add.Input(input[highestOpPos-1], input[highestOpPos+1], '+');
			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("-") == 0){
			input.at(highestOpPos-1) = add.Input(input.at(highestOpPos-1),input.at(highestOpPos+1),'-');
			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("*") == 0){
			input.at(highestOpPos-1) = add.Input(input.at(highestOpPos-1),input.at(highestOpPos+1),'*');
			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("/") == 0){
			input.at(highestOpPos-1) = add.Input(input.at(highestOpPos-1),input.at(highestOpPos+1),'/');
			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare(".") == 0){
			input.at(highestOpPos-1).append(".");
			input.at(highestOpPos-1).append(input.at(highestOpPos+1));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("^") == 0){
			input.at(highestOpPos-1) = powerRanger.InputPower(input[highestOpPos-1],input[highestOpPos+1],'^');
			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("<<") == 0){
			input.at(highestOpPos-1) = bitwise.shiftLeft(BinaryNum::fromOther(input.at(highestOpPos-1)),
														 stoi(input.at(highestOpPos+1)));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare(">>") == 0){
			input.at(highestOpPos-1) = bitwise.shiftRight(BinaryNum::fromOther(input.at(highestOpPos-1)),
														  stoi(input.at(highestOpPos+1)));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("<&") == 0){
			input.at(highestOpPos-1) = bitwise.rotateRight(BinaryNum::fromOther(input.at(highestOpPos-1)),
														   stoi(input.at(highestOpPos+1)));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare(">&") == 0){
			input.at(highestOpPos-1) = bitwise.rotateRight(BinaryNum::fromOther(input.at(highestOpPos-1)),
															   stoi(input.at(highestOpPos+1)));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}
		else if(input.at(highestOpPos).compare("%") == 0){
			input.at(highestOpPos-1) = modular.calculation( std::stoi(input.at(highestOpPos-1)),
															std::stoi(input.at(highestOpPos+1)));

			input.erase(input.begin() + highestOpPos);
			input.erase(input.begin() + highestOpPos);
		}


	}
	std::cout << std::endl;
	if(input.size() != 0)
		return input.at(0);
	else
		return " ";
}

int Input::getHighestPriorityOp(vector<std::string> input){
	int highestOperatorPos = -2;
	int highestOperatorPriority = -1;

	for(unsigned int i = 0; i < input.size(); i++){
		if(!strings::isNumber(input.at(i))){
			if(input.at(i).compare("(") == 0){
				highestOperatorPos = -2;
				highestOperatorPriority = -1;
			}else if(input.at(i).compare(")") == 0){
				break;
			}else{
				if(highestOperatorPriority == -1){
					highestOperatorPriority = getPriority(input.at(i));
					highestOperatorPos = i;
				}
				else if(getPriority(input.at(i)) > highestOperatorPriority){
					highestOperatorPriority = getPriority(input.at(i));
					highestOperatorPos = i;
				}
			}
		}
	}
	if(highestOperatorPos > 0)
		std::cout << "HighOP = " << input.at(highestOperatorPos) << std::endl;
	return highestOperatorPos;
}

vector<string> Input::validateInput(vector<std::string> input){
	for(unsigned int i = 0; i < input.size(); i++){
		//remove redundant parenthesis
		if(input[i].compare("(") == 0){
			for(unsigned int j = i; j < input.size(); j++){
				if((j-i) > 2)
					break;
				if(input[j].compare(")") == 0){
					input.erase(input.begin()+i);
					input.erase(input.begin()+j-1);
				}
			}
		}
		//rebuild split operators e.g">",">" becomes ">>"
		//and turn + - into -
		if(input[i].compare("<") == 0){
			if(i < input.size()-1){
				if(input[i+1].compare("<") == 0){
					input[i].push_back('<');
					input.erase(input.begin()+i+1);
				}
				else if(input[i+1].compare("&") == 0){
					input[i].push_back('&');
					input.erase(input.begin()+i+1);
				}
			}
		}
		else if(input[i].compare(">") == 0){
			if(i < input.size()-1){
				if(input[i+1].compare(">") == 0){
					input[i].push_back('>');
					input.erase(input.begin()+i+1);
				}
				else if(input[i+1].compare("&") == 0){
					input[i].push_back('&');
					input.erase(input.begin()+i+1);
				}
			}
		}
		else if(input[i].compare("+") == 0){
			if(i < input.size()-1){
				if(input[i+1].compare("-") == 0){
					input.erase(input.begin()+i);
				}
			}
		}

		//remove two operators next to each other
		if(!isdigit(input[i].front()) and !isalpha(input[i].front())){
			if(input.size() > i+1){
				if(!isdigit(input[i+1].front()) and !isalpha(input[i+1].front())){
					if(input[i+1].front() != '(' and input[i].front() != ')'){
						input.erase(input.begin()+i+1);
					}
				}
			}
		}

		//remove non recognised characters
		if(isalpha(input[i].front())){
			if(getPriority(input[i]) == -1){
				input.erase(input.begin() + i);
				i--;
			}
		}
	}
	return input;
}

string Input::formatOutput(std::string input){
	//determine string info
	int decimalPointPos = -1;
	for(unsigned int i = 0; i < input.size();i++){
		if(input[i] == '.')
			decimalPointPos = i;
	}
	//remove trailing 0's after decimal point
	if(decimalPointPos != -1){
		for(unsigned int i = input.size(); i > 0; i--){
			if(input[i] == '0')
				input.erase(i);
			if(input[i] == '.')
				break;
		}
	}
	//remove trailing dot
	if(input.back() == '.')
		input.erase(input.size()-1);

	//add seperator character
	if(decimalPointPos == -1 and input.front() != '0'){
		for(unsigned int i = input.size(); i > 0; i--){
			if((input.size() - i+1)%4 == 0 and i != input.size())
				input.insert(i, seperator);
		}
	}

	return input;

}
