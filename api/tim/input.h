#include <string>
#include <vector>

#include "bitwise.h"
#include "constants.h"

#include "api/josh/inversion.h"
#include "api/aleks/add.h"
#include "api/aleks/power.h"

using std::vector;
using std::string;

#ifndef INPUT_H
#define INPUT_H
class Input{
	//settings
	float acuracy = 0.6; //how similar a word must be to be corrected
	
	//word bank operators and a list of synonyms
	vector<string> characters = {"+","-","/","*","^","(",")",".","<",">","&","!"};//no order
	vector<string> shortWords = {"by","the","to","of"};//words that will be removed
	vector<string> plus = {"plus","add"};
	vector<string> minus = {"minus","subtract", "from"};
	vector<string> divide = {"divided","over"};
	vector<string> times = {"times","multiply","x"};
	vector<string> power = {"power"};
	vector<string> invert = {"invert"};

	//charcter inserted every 4 digits to make it look pretty
	string seperator = ",";

	vector<string> operators = {"-","+","/","*","^",".","!"};//in order of priority
	
	/**in class function to replace words with their values inside the array*/
	void replaceWords(vector<string> *input, vector<string> wordArray, string character);

	Bitwise bitwise;
	Constants constants;

	inversionClass inversion;
	Add add;
	Power powerRanger;
public:
	/**takes and input string and a vector, and returns a vector to the individual elements*/
	vector<string> vectoriseInput(string input);
	/**replaces recognised things with things e.g. "plus" with "+"*/
	vector<string> formatInput(vector<string> input);

	/**checks if the input is valid i.e can something be calculated from it*/
	bool valid(string input);
	bool valid(vector<string> inputList);

	/**returns the position in the array of the word bank*/
	int getPriority(string input);

	/**recursively gets a string of contigous digits from a string, modifies the pointer passed to it*/
	void getNumber(string input, string *number, unsigned int position);

	/**recursively gets a string of contigous charcters from a string, modifies the pointer passed to it*/
	void getWord(string input, string *word, unsigned int position);

public:
	/**The function that is responsible for calculating the final result*/
	string calculate(vector<string> input);
	/**returns the position of the highest priority operator in the vector*/
	int getHighestPriorityOp(vector<string> input);
	/**removes redundant parenthesis, operators, non valid characters and returns the modified vector*/
	vector<string> validateInput(vector<string> input);
	/**removes trailing 0's and returns modified string*/
	string formatOutput(string output);
};
#endif
