typedef int Stack_entry;

class Stack {
public:
	Stack();
	bool empty() const;
	int size() const;
	void push(const Stack_entry &item);
	void pop();
	 const Stack_entry & top() const;
	~Stack();
	Stack(const Stack &original);
	void operator =(const Stack &original);
};

Stack::Stack() {
	head = 0;
}
bool Stack::empty() const {
	return head == 0;
}
void size() const {
	int *p = head;
	while (p != 0)
}


typedef Stack MyStack;

int main() {
	MyStack stack;
	cout << stack.empty() << endl;
	cout << stack.size() << endl;
	cout << stack.top() <<endl;
	for (int i = 0; i < 10; ++ i) {
		stack.push(i);
	}
	cout << stack.empty() << endl;
	cout << stack.size() << endl;
	cout << stack.top() <<endl;
	for (int i = 0; i < 8; ++ i) {
		stack.pop();
	}
	cout << stack.empty() << endl;
	cout << stack.size() << endl;
	cout << stack.top() <<endl;

}