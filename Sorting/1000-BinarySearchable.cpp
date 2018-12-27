#include <iostream>
#include <vector>
using namespace std;

bool binarySearch (int X, const vector<int> & vec, int index) {
	int len = vec.size();
	for (int i = 0; i < len; ++i) {
		if (i < index and vec[i] > X) return false;
		if (i > index and vec[i] < X) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	while (cin >> size) {
		vector<int> arr(size);
		int count = 0;
		for (int i = 0; i < size; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < size; ++i) {
			if (binarySearch(arr[i], arr, i))
				count ++;
		}
		cout << count << '\n';
	}
}