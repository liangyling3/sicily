/*
Sample Input Copy
	3
	a
	2-[(1+2)*2]
	(a+b])
Sample Output Copy
	Yes
	Yes
	No
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool matching (const string &str) {
	stack<char> stack;
	for (int i = 0; i < str.size(); ++i) {
		if ((str[i]=='}' and !stack.empty() and stack.top()=='{') or (str[i]==')' and !stack.empty() and stack.top()=='(') or (str[i]==']' and !stack.empty() and stack.top()=='[')) {
			stack.pop();
		}
		else if (str[i]== '{' or str[i]=='('  or str[i]=='[' or str[i]=='}' or str[i]==']' or str[i]==')')
			stack.push(str[i]);
	}
	return stack.empty();
}

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		string str;
		cin >> str;
		if (matching(str) == 1)	cout << "Yes" << endl;
		else cout << "No" << endl;
	}
} 
