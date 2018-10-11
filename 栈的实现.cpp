#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node<T> *next; 
	
	Node() {
		value = 0;
		next = 0;
	} 
	
	~Node() {
		delete next;
	}
};

template <typename T>
class Stack {
private:
	Node<T> *head;		//	the node at the top of the stack 
	int count;
public:
	Stack() {
		head = 0;
		count = 0;
	}
	
	bool empty() const {
		return count == 0;
	}
	
	int size() const {
		return count;
	}
	
	void push(const T &value) {
		Node<T> *node = new Node<T>;	//	new a node
		node->value = value;
		node->next = head;
		head = node;
		count ++;
	}
	
	void pop() {
		Node<T> *temp = head;
		head = head->next;
		temp->next = 0;
		if (temp->next == 0)	delete temp->next; 
		count --;
	}
	
 	const T & top() {
 		return head->value;
	 }
 	
	~Stack() {
		delete head;
	}
	
	Stack(const Stack &original) {
		head = original.head;
		count = original.count;
	}
	
	void operator = (const Stack &original) {
		for (int i = 0; i < count; ++ i) {
			this->pop();
		}
		head = original.head;
		count = original.count;
	}
};

typedef Stack<int> MyStack;

