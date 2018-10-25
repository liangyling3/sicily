/*
Sample Input Copy
	3
	0 1 2
	7
	2 3 4 0 1 2 5

	2
	1 4
	6
	4 1 4 1 4 4

	3
	1 2 3
	7
	3 2 1 3 2 255 7

Sample Output Copy
	3
	1
	no solution
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void checkMatching(const vector<int> &code, const vector<int> &gate) {
	int len1 = code.size(), len2 = gate.size();
	for (int i = 0; i < len2; ++i) {
		if (gate[i] != code[0])	continue;
		int flag = 1;
		for (int j = i; j < i+len1; ++j) {
			if (gate[j] != code[j-i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			cout << i << endl;
			return;
		}
	}
	cout << "no solution" << endl;
}

int main() {
	// 加速输入输出
	std::ios::sync_with_stdio();
	std::cin.tie(0);

	int size;
	while (cin >> size) {
		vector<int> code, gate;
		for (int i = 0; i < size; ++i) {
			int temp;
			cin >> temp;
			code.push_back(temp);
		}
		int size2;
		cin >> size2;
		for (int i = 0; i < size2; ++i) {
			int temp;
			cin >> temp;
			gate.push_back(temp);
		}
		checkMatching(code, gate);
	}
}