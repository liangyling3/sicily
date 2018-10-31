#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
	queue<BinaryNode<T>*> queue;
	T data;
	int count = 1;
	if (root == NULL) {
		return;
	}
	queue.push(root);
	while (!queue.empty()) {
		if (queue.front()->left != NULL) {
			queue.push(queue.front()->left);
		}
		if (queue.front()->right != NULL) {
			queue.push(queue.front()->right);
		}
		data = queue.front()->elem;
		count ++;
		queue.pop();
	}
}