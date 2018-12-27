#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

ostream & operator << (ostream & out, const vector<pair<int, int> > & vec) {
	int size = vec.size();
	for (int i = 0; i < size; ++i) {
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	int tag = 0;
	while (cin >> size) {
		if (tag != 0) cout << '\n';
		tag = 1;
		int * arr = new int[size]; 
		for (int i = 0; i < size; ++i) {
			cin >> arr[i];
		}
		sort(arr,arr+size);		// 排序
		vector<pair<int, int> > data;
		pair<int, int> first(arr[0], 1);
		data.push_back(first);
		int index = 0;

		for (int i = 1; i < size; ++i) {
			if (arr[i] == arr[i-1]) {
				data[index].second ++;
			} else {
				pair<int, int> temp(arr[i], 1);
				data.push_back(temp);
				index ++;
			}
		}
		cout << data;
	}
}