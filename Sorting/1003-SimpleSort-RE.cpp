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
		int row, col;
		cin >> row >> col;
		vector<vector<int> > arr, store;
		for (int i = 0; i < row; ++i) {
			vector<int> temp(col);
			for (int j = 0; j < col; ++j) {
				cin >> temp[j];
			}
			temp.push_back(i);			// 存储输入时的序号
			arr.push_back(temp);
		}
		store = arr;

		int Q;
		cin >> Q;
		while (Q--) {
			vector<int> pri(col);
			for (int i = 0; i < col; ++i) {
				cin >> pri[i];
			} 
			vector<int> tempVec = pri;
			sort(tempVec.begin(), tempVec.end());		// 将Q中顺序改为用0到col-1表示
			for (int i = 0; i < col; ++i) {
				for (int j = 0; j < col; ++j) {
					if (pri[i] == tempVec[j]) {
						pri[i] = j;
						break;
					}
				}
			}

			for (int i = 0; i < row; ++i) {		// 冒泡排序
				for (int j = row-1; j > i; --j) {
					if (arr[j][pri[0]] < arr[j-1][pri[0]]) {
						auto temp = arr[j];
						arr[j] = arr[j-1];
						arr[j-1] = temp; 
					}
				}
			}

			int index = 0;
			for (int i = 0; i < row-1; ++i) {
				while (index < col and arr[i][pri[index]] == arr[i+1][pri[index]]) {
					++ index;
					if (arr[i][pri[index]] > arr[i+1][pri[index]]) {
						auto temp = arr[i];
						arr[i] = arr[i+1];
						arr[i+1] = temp; 
						break;
					}
				}
				index = 0;
			}

			for (int i = 0; i < row; ++i) {
				cout << arr[i][col] << ' ';
			}
			cout << '\n';
			arr = store;
		}
	}
}