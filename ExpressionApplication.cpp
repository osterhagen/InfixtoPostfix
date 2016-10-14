#include "ExpressionApplication.h"
#include <string>
#include "ShuntingYard.h"

using namespace std;

BinaryTree *
ExpressionApplication::buildExpressionTree(vector<Token> &v) {
	//TODO 3
// copy and paste code from bottom
    return _expression;
}

ExpressionApplication::ExpressionApplication(vector<Token> &v) {
	//TODO 2
    stack<Token> temp;
    int i = 0;
    int j = 0;
    _expression = new BinaryTree();
    _expression -> _root = new TreeNode(v[v.size() - 1]);
    //_expression -> _root -> _left = new TreeNode(v[0]);

    while (i < v.size()) i++;
    while (j < i) {
        if ( v[j].elementType == integer) {
            temp.push(v[j]);
        }
        else if (v[j].elementType == identifier) {
            temp.push(v[j]);
        }
        else if (v[j].elementType == operation) {

            if (_expression -> _root -> _left == NULL && temp.size() > 0 && temp.size() <= 2) { // check if it is there
                _expression->_root->_left = new TreeNode(v[j]);
                _expression->_root->_left->_left = new TreeNode(temp.top());
                temp.pop();
                _expression->_root->_left->_right = new TreeNode(temp.top());
                temp.pop();
            }
            else if (_expression -> _root -> _left != NULL && temp.size() > 0 && temp.size() <= 2) { // if there is already something there
                _expression->_root->_right = new TreeNode(v[j]);
                _expression->_root->_right->_left = new TreeNode(temp.top());
                temp.pop();
                _expression->_root->_right ->_right = new TreeNode(temp.top());
                temp.pop();
            }
            else if (temp.size() == 1 && temp.top().elementType == operation) {
                _expression -> _root = temp.top();
                temp.pop();
            }



        }
        j++;
    }

}

ExpressionApplication::~ExpressionApplication() {
	//TODO 2

}

TreeNode * ExpressionApplication::differentiate(bool isPowerOp, char target) {
	//TODO 5
}

BinaryTree * ExpressionApplication::differentiate(char target) {
	//TODO 5
}

BinaryTree *
ExpressionApplication::simplify() {
	//TODO 4
}


