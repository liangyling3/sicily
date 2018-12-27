#include <iostream>
#include <string>
using namespace std;

int strToNum(const string & str) {
	int len = str.size();
	int result = 0;
	for (int i = 0; i < len; ++i) {
		result = result*10 + (str[i]-'0');
	}
	return result;
} 

bool isNum(char c) {
	return c >= '0' and c <= '9';
}

void decode(const string & str) {
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if (isNum(str[i])) continue;

		if (!isNum(str[i]) and !isNum(str[i+1]))
			cout << str[i];

		if (!isNum(str[i]) and isNum(str[i+1])) {
			string number;
			for (int j = i+1; j < len; ++j) {
				if (!isNum(str[j])) break;
				number.push_back(str[j]);
			}
			int num = strToNum(number);
			while (num--) {
				cout << str[i];
			}
		} 
	}
	cout << '\n';
}

int main() {
	string str;
	while (cin >> str) {
		if (str == "XXX") break;
		decode(str);
	}
}