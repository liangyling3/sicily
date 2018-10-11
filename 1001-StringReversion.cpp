/*
Sample Input
	3
	John_Smith
	int_45
	_me
Sample Output
	nhoJ_htimS
	tni_54
	_em
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverse(string &str) {
	string sub1, sub2;
	stack<char> stack1, stack2;
	
	for (int i = 0; i < str.size(); ++i) {
		if(str[i] == '_') {
			for (int j = i+1; j < str.size(); ++j) 
				stack2.push(str[j]);
			break;
		}
		stack1.push(str[i]);
	}
	int len1 = stack1.size(), len2 = stack2.size();
	for (int i = 0; i < len1; ++i)	{
		sub1.push_back(stack1.top());
		stack1.pop();
	}
	for (int i = 0; i < len2; ++i) {
		sub2.push_back(stack2.top());
		stack2.pop();
	}
	if (len2 != 0)	str = sub1 + '_' + sub2;
	else 	str = sub1;
}

ostream & operator << (ostream &out, const string &str) {
	for (int i = 0; i < str.size(); ++i) {
		out << str[i];
	}
	return out;
}

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		string str;
		cin >> str;
		reverse(str);
		cout << str << endl;
	}
}
