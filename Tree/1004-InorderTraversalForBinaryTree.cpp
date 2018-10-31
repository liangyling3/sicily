// Task: 
// Implement binary tree traversal using both recursion and non-recursion.

#include <iostream>
#include <stack>
using namespace std;

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)) {
	// void (*visit): 函数指针
	// 代表一个泛用的过程
	// (T &x): 指针参数，类型是二叉树结点的模板
	if (root != NULL) {
		inorder_recursive(root->left, visit);
		visit(root->elem);
		inorder_recursive(root->right, visit);
	}
}
 
// root is a pointer to the root of the binary tree.
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)) {
	// 首先判断根结点！=0且栈不为空，在while循环中将根及其左节点依次压入栈中
	// 然后使用visit函数访问elem，并将顶点pop出来，再访问右结点
	stack<BinaryNode<T>* > stack;
	while ((root!=NULL) || (!stack.empty() )) {
		while (root != NULL) {
		  stack.push(root);
		  root = root->left;
		}
		if (!stack.empty()) {
		  root = stack.top();
		  stack.pop();
		  visit(root->elem);
		  root = root->right;
		}
	}
}