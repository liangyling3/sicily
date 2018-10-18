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
/*然而…这道题并没有这么麻烦！！！用一个vector存储已经匹配过的lines就可以了！！*/

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

int getMaxPair(vector<string> lines) {
	if (lines.size()==0) return 0;
	int max = 0, countPair = 0;
	for (int i = 0; i < lines.size()-1; ++i) { 
		for (int j = i+1; j < lines.size(); ++j) {
			if (checkPair(lines[i], lines[j]) == 1) { 
				vector<string> temp = lines;
				temp.erase(temp.begin()+i);
				temp.erase(temp.begin()+j);
				countPair = 1 + getMaxPair(temp); 
			}
		}
		if (countPair > max)
			max = countPair;
	} 
	return max;
}

int main() {
	// 加速输入输出
	std::ios::sync_with_stdio(); 
	std::cin.tie(0);

	int group;
	cin >> group;
	for (int i = 0; i < group; ++i) {
		// 输入
		vector<string> lines;
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			string str;
			cin >> str;
			lines.push_back(str);
		}
		cout << getMaxPair(lines) << endl;
	}
}