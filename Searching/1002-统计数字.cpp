#include <iostream>
#include <algorithm>
using namespace std;

int num[10000][200000];

void count(int * arr, int size) {
	for (int i = 0; i < size; ++i) {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	while (cin >> size) {
		int * arr = new int[size];
		for (int i = 0; i < size; ++i) {
			cin >> arr[i];
		}
		count(arr, size);
		delete [] arr;
	}
}