#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		if (n == 0 and m == 0) 
			return 0;

		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				cout << arr[i];
			}
			else if (i % m == 0) {
				cout << ' ' << arr[i];
			}
			if (n % m != 0) {
				int index = (n / m) * m;
				if (i == index)
					cout << ' ' << arr[i];
			}
		}
		cout << '\n';
	}
}