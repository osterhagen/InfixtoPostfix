#include "ExpressionApplication.h"



using namespace std;

BinaryTree *
ExpressionApplication::buildExpressionTree(vector<Token> &v) {
	//TODO 3
// copy and paste code from bottom
    const int size = v.size() - 1;
    int i = size-1;
    _expression = new BinaryTree();
    _expression -> _root = new TreeNode(v[size]);
    TreeNode * current = _expression -> _root;
    while (i > -1) {
        if(current)
            if (current->_right == NULL) {
                if (v[i].elementType == operation) {
                    current->_right = new TreeNode(v[i]);
                    current->_right->_parent = current;
                    current = current->_right;
                } else {
                    current->_right = new TreeNode(v[i]);
                    current->_right->_parent = current;

                }
            } else if(current ->_left == NULL) {
                if (v[i].elementType == operation) {
                    current->_left = new TreeNode(v[i]);
                    current->_left->_parent = current;
                    current = current->_left;
                } else {
                    current->_left = new TreeNode(v[i]);
                    current->_left->_parent = current;

                }
            } else {
                current = current -> _parent ;
                i++; }

        i--;
    }
    return _expression;
}

ExpressionApplication::ExpressionApplication(vector<Token> &v) {
	//TODO 2
    const int size = v.size() - 1;
    int i = size-1;
    _expression = new BinaryTree();
    _expression -> _root = new TreeNode(v[size]);
    TreeNode * current = _expression -> _root;
    while (i > -1) {
        if(current)
        if (current->_right == NULL) {
            if (v[i].elementType == operation) {
                current->_right = new TreeNode(v[i]);
                current->_right->_parent = current;
                current = current->_right;
            } else {
                current->_right = new TreeNode(v[i]);
                current->_right->_parent = current;

            }
        } else if(current ->_left == NULL) {
            if (v[i].elementType == operation) {
                current->_left = new TreeNode(v[i]);
                current->_left->_parent = current;
                current = current->_left;
            } else {
                current->_left = new TreeNode(v[i]);
                current->_left->_parent = current;

            }
        } else {
            current = current -> _parent ;
            i++; }

        i--;
    }
}



ExpressionApplication::~ExpressionApplication() {
	//TODO 2
    del(_expression -> _root);
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
    _expression = new BinaryTree();
    TreeNode * current = _expression -> _root;
    while (current != NULL) {
        //if ((current -> _right->t->_num == 0 || current -> _left ==0)&& )

    }


}


