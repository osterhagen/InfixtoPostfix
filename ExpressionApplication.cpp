#include "ExpressionApplication.h"
#include "ShuntingYard.h"

using namespace std;

BinaryTree *
ExpressionApplication::buildExpressionTree(vector<Token> &v) {
	//TODO 3


}

ExpressionApplication::ExpressionApplication(vector<Token> &v) {
	//TODO 2


}

ExpressionApplication::~ExpressionApplication() {
	//TODO 2
	//also need to delete rest of tree
	_expression -> _root;
	delete _expression;
}


TreeNode * differentiate(bool isPowerOp, char target) {
	//TODO 5
}

BinaryTree *
ExpressionApplication::simplify() {
	//TODO 4
}


