/*
Sample Input Copy
	2
	3
	ATCG
	TAGC
	TAGG
	2
	AATT
	ATTA
Sample Output Copy
	1
	0
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool mkPair(char a, char b) {
	return (a=='A' and b=='T') or (a=='T' and b=='A') or (a=='C' and b=='G') or (a=='G' and b=='C');
}

bool checkPair(const string &s1, const string &s2) {
	if (s1.size() != s2.size()) return 0;

	int len = s1.size();
	for (int i = 0; i < len; ++i) {
		if (!mkPair(s1[i],s2[i]))	return 0;
	}
	return 1;
}

int main() {
	int group;
	cin >> group;
	for (int i = 0; i < group; ++i) {
		// 输入
		vector<string> lines;
		vector<int> isUsed;
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			string str;
			cin >> str;
			lines.push_back(str);
			isUsed.push_back(0);
		}

		int count = 0; 
		for (int j = 0; j < num-1; ++j) {
			if(!isUsed[j]) {
				for (int k = j+1; k < num; ++k) {
					if (!isUsed[k] && checkPair(lines[j], lines[k])) {
						count ++;
						isUsed[j] = isUsed[k] = 1;
						break;		// 此时不必再进行j与其他的配对，跳出当前循环
					}
				}
			}
		}
		cout << count << endl;
	}
}