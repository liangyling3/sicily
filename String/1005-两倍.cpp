#include <iostream>
#include <vector>
using namespace std;

void countDb(const vector<int> & numbers) {
	int len = numbers.size();
	int count = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (j == i)	continue;
			if (numbers[j] == numbers[i] * 2) count++;
		}
	}
	cout << count << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> numbers(n);
		for (int i = 0; i < n; ++i) {
			cin >> numbers[i];
		}
		countDb(numbers);
	}
}