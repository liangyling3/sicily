// 递归
// sample input
// 		GDAFEMHZ
//		ADEFGHMZ
// sample output
// 		AEFDHZMG
#include <iostream>
#include <string>
using namespace std;

string getPost(string pre, string in) {
	int len = pre.size();
	if (len == 0) return "";
	string post, root = pre.substr(0, 1);
	int index = in.find(pre[0]);
	post = getPost(pre.substr(1, index), in.substr(0, index)) 
		+ getPost(pre.substr(index+1, len-index-1), in.substr(index+1, len-index-1)) 
		+ root;
	return post;
}

int main() {
	string pre, in;
	cin >> pre >> in;
	cout << getPost(pre, in) << '\n';
}