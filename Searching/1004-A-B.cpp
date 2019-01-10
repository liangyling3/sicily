#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二分查找，找到该值在数组中的下标，否则为-1
bool binSearch(const vector<int> & arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return 1;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		// 输入数字并进行去重
		int m, n;
		cin >> m;
		vector<int> A(m);
		for (int i = 0; i < m; ++i) {
			cin >> A[i];
		}
		sort(A.begin(),A.end());
		auto end = unique(A.begin(),A.end());
		A.erase(end, A.end());	// 删除重复的数字

		cin >> n;
		vector<int> B(n);
		for (int i = 0; i < n; ++i) {
			cin >> B[i];
		}
		sort(B.begin(),B.end());
		end = unique(B.begin(), B.end());
		B.erase(end, B.end());

		vector<int> result;
		int size = A.size();
		/* 这里超时了！！
		for (int i = 0; i < size; ++i) {
			auto it = find(B.begin(), B.end(), A[i]);
			if (it == B.end()) {
				result.push_back(A[i]);
			}
		} */
		for (int i = 0; i < size; ++i) {
			if(binSearch(B,A[i]) == 0)
				result.push_back(A[i]);
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