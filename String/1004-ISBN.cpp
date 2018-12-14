#include <iostream>
#include <string>
using namespace std;

string getNumStr(const string & str) {
	string result;
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if (str[i] != '-')
			result.push_back(str[i]);
	}
	return result;
}

void calculate(const string & str) {
	string numbers = getNumStr(str);
	int sum = 0, parity = 0;
	for (int i = 10, j = 0; i >= 2; --i, ++j) {
		sum = sum + (numbers[j] - '0') * i;
	}

	while ((sum + parity) % 11 != 0) {
		parity ++;
	}
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		cout << str[i];
	}

	if (parity == 10) {
		cout << "-X\n";
	} else {
		cout << "-" << parity << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while (cin >> str) {
		calculate(str);
	}
}