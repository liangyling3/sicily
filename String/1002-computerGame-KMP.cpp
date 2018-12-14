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
#include <algorithm>
using namespace std;

int * getNext(int * code, int len) {
	int next[len];
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < len - 1) {

       if (k == -1 || code[j] == code[k]) {
           next[++j] = ++k;
       } else {
           k = next[k];
       }
    }
    return next;
}

void checkMatching(int *code, int *gate, int len1, int len2) {
	int i = 0, j = 0;
	int *next = getNext(code, len1);
	while (i < len2 and j < len1) {
		if (j == -1 or gate[i] == code[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
	}

	if (j == len1) {
		cout << i-j << '\n';
	}
	else {
		cout << "no solution\n";
	}
}

int main() {
	std::ios::sync_with_stdio();
	std::cin.tie(0);

	int size;
	while (cin >> size) {
		int *code = new int[size];
		for (int i = 0; i < size; ++i) {
			cin >> code[i];
		}

		int size2;
		cin >> size2;
		int *gate = new int[size2];
		for (int i = 0; i < size2; ++i) {
			cin >> gate[i];
		}
		checkMatching(code, gate, size, size2);
		delete [] code;
		delete [] gate;
	}
}