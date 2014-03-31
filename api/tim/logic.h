#include "number.h"

using std::string;

#ifndef LOGIC_H
#define LOGIC_H
class Logic{
public:
	inline bool andF(bool op1, bool op2){return (op1 and op2)? true : false;}
	inline bool orF(bool op1, bool op2){return (op1 or op2)? true : false;}
	inline bool xorF(bool op1, bool op2){return (op1 xor op2)? true : false;}
	inline bool notF(bool op){return not op;}
	inline bool nandF(bool op1, bool op2){return not (op1 and op2)? true : false;}
	inline bool norF(bool op1, bool op2){return not(op1 or op2)? true : false;}
	inline bool xnorF(bool op1, bool op2){return (op1 != op2)? true : false;}
	
	string 	andF(BinaryNum op1, BinaryNum op2);
	string 	orF(BinaryNum op1, BinaryNum op2);
	string 	xorF(BinaryNum op1, BinaryNum op2);
	string 	nandF(BinaryNum op, BinaryNum op2);
	string 	norF(BinaryNum op, BinaryNum op2);
	string 	xnorF(BinaryNum op, BinaryNum op2);
	string 	notF(BinaryNum op);
};
#endif //BITWISE_H
