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
	stack<double> stack;
	int len = str.size();
	for (double i = 0; i < len; ++i) {
		if (str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/') {
			double num1 = stack.top();
			stack.pop();
			double num2 = stack.top();
			stack.pop();
			
			if (str[i] == '+')	stack.push(num1+num2);
			if (str[i] == '-')	stack.push(num2-num1);
			if (str[i] == '*')	stack.push(num1*num2);
			if (str[i] == '/')	stack.push(num2/num1);

		}
		else stack.push(str[i]-'a'+1);
	}
	double result = stack.top();
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


