#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool matching(const string & str) {
	stack<char> stack;
	int size = str.size();
	for (int i = 0; i < size; ++i) {
		if ((!stack.empty()) and ((str[i]=='}' and stack.top()=='{') or
			(str[i]==']' and stack.top()=='[') 
			or (str[i]==')' and stack.top()=='('))) {
			stack.pop();
		}
		else if (str[i]=='[' or str[i]=='{' or str[i]=='}' or str[i]==']' or
			str[i]=='(' or str[i]==')' ) {
			stack.push(str[i]);
		}
	} 
	return stack.empty();
} 

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		if (matching(str)) 
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}