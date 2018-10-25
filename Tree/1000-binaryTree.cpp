// 输入树的先序和后序，求符合要求树的个数
// 没有单子树存在的情况：只有一棵树符合要求
// 有单子树存在的情况：单子树可能为左or右使得有不同的可能性
// 假设有n棵单子树，则存在2^n棵树符合要求 

// 如何求单子树的个数？
// 规律：a[i]==b[j]时，a[i+1]==b[j-1]则产生一个特殊结点（单子树）

// sample input: 
// 	ABCD
// 	CBDA
// sample output: 2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getTree(const string &preLine, const string &postLine) {
	int count = 1;
	int len = preLine.size();
	if (len <= 1) return 1;

	for (int i = 1; i < len; ++i) {
		int index = postLine.find(preLine[i]);
		if (preLine[i-1] == postLine[index+1]) count *= 2;
	} 
	return count;
}

int main() {
	 string preLine, postLine;
	 cin >> preLine >> postLine;
	 cout << getTree(preLine, postLine);
}