#include <iostream>
#include <queue>
using namespace std;

template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
	queue<BinaryNode<T>*> queue;

	if (root == NULL) return;
	queue.push(root);
	while (!queue.empty()) {
		if (queue.front()->left != NULL) {
			queue.push(queue.front()->left);
		}
		if (queue.front()->right != NULL) {
			queue.push(queue.front()->right);
		}
		visit(queue.front()->elem);
		queue.pop();
	} 
}