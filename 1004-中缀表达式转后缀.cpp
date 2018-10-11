/*
Sample Input Copy
	A+B*C-D-E/F
Sample Output Copy
	ABC*+D-EF/-
*/

#include <iostream>
#include <string>
using namespace std;

bool isLetter(char c) {
	return (c>='a' and c <='z') or (c>='A' and c<='Z');
}

void infixToPostfix(string &infix) {
	string postfix;
	if (infix[1]=='+' or infix[1]=='-')
	{
		postfix.push_back(infix[0]);
	}
	for (int i = 0; i < infix.size(); ++i) {
		if (infix[i]=='+' or infix[i]=='-') {
			string temp;
			for (int j = i+1; j < infix.size(); ++j) {
				if (infix[j]=='+' or infix[j]=='-') break;
				if (isLetter(infix[j]))	{
					postfix.push_back(infix[j]);
				}
				else temp.push_back(infix[j]);
			}
			postfix = postfix + temp + infix[i];
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