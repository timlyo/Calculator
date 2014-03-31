#include "logic.h"
#include "number.h"


string Logic::andF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		answer[i] = (op1[i] == '1' and op2[i] == '1')? '1' : '0';
	}
	return answer;
}

string Logic::orF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		answer[i] = (op1[i] == '1' or op2[i] == '1')? '1':'0';
	}
	return answer;
}

string Logic::xorF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		answer[i] = (op1[i] == '1' xor op2[i] == '1')? '1':'0';
	}
	return answer;
}

string Logic::notF(BinaryNum op){
	if(op.isValid() == 0)
		return "e";
	
	string answer;
	answer.resize(op.size());
	for(unsigned int i = 0; i < op.size(); i++){
		answer[i] = (op[i] == '0')? '1':'0';
	}
	return answer;
}

string Logic::nandF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		if(op1[i] == '1' and op2[i] == '1')
			answer[i] = '0';
		else
			answer[i] = '1';
	}
	return answer;
}

string Logic::norF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		if(op1[i] == '1' or op2[i] == '1')
			answer[i] = '0';
		else
			answer[i] = '1';
	}
	return answer;
}

string Logic::xnorF(BinaryNum op1, BinaryNum op2){
	if(op1.isValid() == 0 and op2.isValid() == 0)
		return "e";
	
	op1.padBinary(&op2);
	string answer;
	answer.resize(op1.size());
	for(unsigned int i = 0; i < op1.size(); i++){
		if( op1[i] == op2[i])
			answer[i] = '1';
		else
			answer[i] = '0';
	}
	return answer;
}
