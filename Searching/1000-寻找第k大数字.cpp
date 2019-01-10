#include <iostream>
using namespace std;

int arr[20000001] = {0};
int findk(int size, int k);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	int max = -10000000;
	cin >> n >> k;
	cout << findk(n, k) << '\n';
}

int findk(int n, int k) {
	for (int i = 0; i < n; ++i) {
		int index;
		cin >> index;
		arr[index+10000000] = 1;
		if (index > max) 
			max = index;
	}

	int count = 0;
	for (int i = max+10000000; i > 0; --i) {
		if (arr[i] == 1) {
			count ++;
			if (count == k) {
				return i-10000000;
			}
		}
	}
}