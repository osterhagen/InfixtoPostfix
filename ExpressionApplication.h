#include "BinaryTree.h"
#include <vector>
#include <stdio.h>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class ExpressionApplication {
public:
	BinaryTree * _expression;
	
	ExpressionApplication(vector<Token> &v);
	~ExpressionApplication();
	TreeNode * differentiate(bool isPowerOp, char target);
	BinaryTree * differentiate(char target);
	BinaryTree * simplify();
	BinaryTree * buildExpressionTree(vector<Token> &v);
    void del(TreeNode *root) {
        if (root != NULL) {
            del(root->_left);
            del(root->_right);
            delete root;
        }
    }
};
