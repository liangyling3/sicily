/*
Sample Input Copy
	A+B*C-D-E/F
Sample Output Copy
	ABC*+D-EF/-
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLetter(char c) {
	return (c>='a' and c <='z') or (c>='A' and c<='Z');
}

bool isOperator (char c) {
	return c=='+' or c=='-' or c=='*' or c=='/' or c=='%';
}

int compare (char a, char b) {
	int temp;
	if ((a=='+' or a=='-') and (b=='*' or b=='/')) temp = -1;
	if ((a=='+' or a=='-') and (b=='+' or b=='-')) temp = 0;
	if ((a=='*' or a=='/') and (b=='*' or b=='/')) temp = 0;
	if ((a=='*' or a=='/') and (b=='+' or b=='-')) temp = 1;
	return temp;
}

void infixToPostfix(string &infix) {
	string postfix;
	stack<char> stack;
	int len = infix.size();
	for (int i = 0; i < len; ++i) {
		if (isLetter(infix[i]))	
			postfix += infix[i];
		if (isOperator(infix[i]) or infix[i] == '(') {
			while (!stack.empty() and (compare(infix[i],stack.top()) == -1 or compare(infix[i],stack.top()) == 0)) { 	// 优先级低于或等于栈顶元素	 
				postfix += stack.top();
				stack.pop();
			}
			stack.push(infix[i]);
		}
		if (infix[i] == ')') {
			while (stack.top() != '(') {
				postfix += stack.top();
				stack.pop();
			}
			stack.pop();					// 弹出'('
		}
		if (i == len-1) {
			while(!stack.empty()) {
				postfix += stack.top();
				stack.pop();
			}
		}
	}
	infix = postfix;
}

int main()
{
	string str;
	cin >> str;

	infixToPostfix(str);
	cout << str;
}