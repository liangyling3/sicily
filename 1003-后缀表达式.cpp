/*
Sample Input 
	2
	ab+c*
	int**py++
Sample Output 
	9.00
	2561.00
*/

#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

double calculate(const string &str) {
	stack<char> stack;
	double result = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (!stack.empty() and (str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/')) {
			int num1, num2;
			num1 = stack.top()-'a'+1;
			stack.pop();
			
			if (result == 0 and !stack.empty()) {
				num2 = stack.top()-'a'+1;
				stack.pop();
			}
			else num2 = result;
			
			if (str[i] == '+')	result = num1+num2; 
			if (str[i] == '-')	result = num1-num2;
			if (str[i] == '*')	result = num1*num2;
			if (str[i] == '/')	result = num1/num2;
		}
		else stack.push(str[i]);
	}
	return result;
}

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		string str;
		cin >> str;
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << calculate(str) << endl;
	}
}
