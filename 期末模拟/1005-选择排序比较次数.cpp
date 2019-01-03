#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int result = 0;
		for (int i = n-1; i > 0; --i) {
			result += i;
		}
		cout << result << '\n';
	}
}