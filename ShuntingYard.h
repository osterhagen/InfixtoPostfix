#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Token.h"

const int precedence[5][3] = {
	{'^', 4, 0},
	{'*', 3, 1},
	{'/', 3, 1},
	{'+', 2, 1},
	{'-', 2, 1}
};



class Shuntingyard {
public:
	char * _string;
    std::stack< Token > out;
    std::stack<Token> op;
	Shuntingyard(char * s) {
		_string = strdup(s);
	}

	~Shuntingyard() {
		delete _string;
	}


};

