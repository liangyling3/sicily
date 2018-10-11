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
#include <vector>
using namespace std;

void reverse(string &str) {
	int index = -1;
	string sub1, sub2;
	
	for (int i = 0; i < str.size(); ++i) {
		if(str[i] == '_') {
			index = i;
			break;
		}
	}
	
	if (index != -1) {
		for (int i = index-1; i >= 0; --i) 
			sub1.push_back(str[i]);
		for (int i = str.size()-1; i > index; --i) 
			sub2.push_back(str[i]);
		str = sub1 + '_' + sub2;
	}
	else {
		for (int i = str.size()-1; i >= 0; -- i) 
			sub1.push_back(str[i]);
		str = sub1;
	}
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
	vector<string> strings;
	for (int i = 0; i < size; ++i) {
		string str;
		cin >> str;
		reverse(str);
		strings.push_back(str);
	}
	for (int i = 0; i < strings.size(); ++i) {
		cout << strings[i] << endl;
	}
}
