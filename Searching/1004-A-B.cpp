#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int m, n;
		cin >> m;
		vector<int> A;
		while (m--) {
			int num;
			cin >> num;
			auto it = find(A.begin(), A.end(), num);
			if (it == A.end()) {		// 此处只放入不等的数，避免重复运算
				A.push_back(num);
			}
		}

		cin >> n;
		vector<int> B;
		while(n--) {
			int num;
			cin >> num;
			B.push_back(num);
		}

		vector<int> result;
		int size = A.size();
		for (int i = 0; i < size; ++i) {
			auto it = find(B.begin(), B.end(), A[i]);
			if (it == B.end()) {
				result.push_back(A[i]);
			}
			else { // 若相等，则在B中删除（不会再等于其他A中的数）
				B.erase(it);
			}
		}

		sort(result.begin(), result.end());
		int len = result.size();
		for (int i = 0; i < len; ++i) {
			cout << result[i];
			if (i != len-1) cout << ' ';
		}
		cout << '\n';
	}
}