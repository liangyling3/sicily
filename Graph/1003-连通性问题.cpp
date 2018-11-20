// 并查集：通过判断某两个结点是否有共同祖先来判断这两个结点是否连通
// 避免重复查找：只需要在第一次往上找的时候，就将每个节点的父节点更新为最终祖先节点

#include <iostream>
using namespace std;

int set[100001];

int findSet(int p) {
	return p == set[p] ? p : (set[p]=findSet(set[p]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p,q;
	for (int i = 0; i < 100001; ++i) {
		set[i] = i;
	}
	while (cin >> p >> q) {
		if (findSet(p) != findSet(q)) {
			cout << p << ' ' << q << '\n';
			set[findSet(p)] = set[findSet(q)];
		}
	}
}

