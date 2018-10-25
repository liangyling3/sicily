/*
Sample Input:
	This lines must be printed backwards and splitted in the middle.
	And each line too!
	hellow my friend
	how are you today
	i hope you're fine

	be cool, be nice.

Sample Output:
	 hcae dnA!oot enil
	wkcab detnirp eb tsum senil sihT.elddim eht ni dettilps dna sdra
	y era wohyadot uo
	m wollehdneirf y
	oy epoh ienif er'u
	 ,looc eb.ecin eb
*/

#include <iostream>
#include <string>
using namespace std;

bool checkEmpty(const string &str) {
	if (str == "")	return 1;

	int len = str.size(), count = 0;
	for (int i = 0; i < len; ++i) {
		if(str[i] == ' ') 
			count++;
	}
	if (count == len) return 1;
	return 0;
} 

void switchText(string &str) {
	int len = str.size();
	string temp;
	if (!checkEmpty(str) and len>1) {
		if (len % 2 == 0) {
			for (int i = len/2-1; i >= 0; --i) 
				temp.push_back(str[i]);
			for (int i = len-1; i >= len/2; --i) 
				temp.push_back(str[i]);
		}
		else {
			for (int i = len/2; i >= 0; --i)
				temp.push_back(str[i]);
			for (int i = len-1; i > len/2; --i)
				temp.push_back(str[i]);
		}
		str = temp;
	}
	if (checkEmpty(str))
		return;
	cout << str << endl;
}

int main() {
	// 要求成对处理
	string str1,str2;
	while (getline(cin, str1)) {	// 若能读到第一行，则第二行必定存在
		getline(cin, str2);
		switchText(str2);
		switchText(str1);
	}
	return 0;
}