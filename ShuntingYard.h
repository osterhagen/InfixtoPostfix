#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "Token.h"

const int precedence[5][3] = {
	{'^', 4, 0},
	{'*', 3, 1},
	{'/', 3, 1},
	{'+', 2, 1},
	{'-', 2, 1}
};

int cardinality(Token w) {
	char s = w._op;
	for (int i = 0; i < 5; i++) {
		if (precedence[i][0] == s)
			return precedence[i][1];
	}
	return 0;

}
// added for checking right or left associative
int associativity(Token w) {
	char s = w._op;
	for (int i = 0; i < 5; i++) {
		if (precedence[i][0] == s)
			return precedence[i][2];
	}
	return -1;
}

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




	// added for checking cardinality

	std::vector<Token> infixToPostfix() {
		//TODO 1
		int i = 0;
		while ( _string[i]  != '\0') {
			Token c = _string[i];

			if (c.elementType == integer || c.elementType == identifier)
				out.push(c);

			else if ( c.elementType == operation) {
				if (op.empty())
					op.push(c);
				else {
					while (!op.empty()) {
						if (cardinality(op.top()) > cardinality(c) || cardinality(c) == cardinality(op.top()) && associativity(c) != 0) {
							out.push(op.top());
							op.pop();
						} else break;
					} op.push(c);
				}
			}
			i++;

		}
		//int x = op.size();
		for (int j = 0; j < op.size(); j++) {

			out.push(op.top());
			op.pop();
		}
		//cout << '\n' << op.size();
		std::vector<Token> output (out.size() , ' ');

		for (unsigned int l = out.size(); l > 0; l--) {
			output[l -1] = out.top();
			out.pop();
		}

		return output;
	}

};
