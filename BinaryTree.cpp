#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	_root = NULL;
}


BinaryTree::~BinaryTree() {
    del(_root);
}

void printTree(TreeNode * root) {
	if(root == NULL) return;
	if(root -> t -> elementType == operation) {
		putchar('(');
		fflush(stdout);
	}
	printTree(root -> _left);
	root -> t -> print();
	printTree(root -> _right);
	if(root -> t -> elementType == operation) {
		putchar(')');
		fflush(stdout);
	}
}

void
BinaryTree::print() {
	printTree(_root);
	putchar('\n');
}
