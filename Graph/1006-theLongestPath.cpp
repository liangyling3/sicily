#include <iostream>
#include <vector>
using namespace std;

int adj[101][101];
int isVisited[101];
vector<int> paths;

int getLongestPath();
void dfs(int v, int deep);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	cin >> size;
	while (size--) {
		for (int i = 0; i < 101; ++i) {			// 清空邻接矩阵
			for (int j = 0; j < 101; ++j) {
				adj[i][j] = 0;
			}		
		}
		int edge;
		cin >> edge;
		while (edge--) {			// 输入边
			int m, n;
			cin >> m >> n;
			adj[m][n] = 1;
			adj[n][m] = 1;
		}
		
		cout << getLongestPath() << '\n';
	}
}

int getLongestPath() {
	dfs(1, 0);
	int size = paths.size();
	int max1 = 0, max2 = 0, index = 0;
	for (int i = 0; i < size; ++i) {
		if (paths[i] > max1) {
			index = i;
			max1 = paths[i];
		}
	}
	for (int i = 0; i < size; ++i) {
		if (paths[i] > max2 and i != index)
			max2 = paths[i];
	}
	return max1 + max2;
}

void dfs(int v, int deep) {
	isVisited[v] = 1;
	int tag = 0;
	for (int i = 0; i < 101; ++i) {
		if (adj[v][i] and !isVisited[i]) {
			tag = 1;
			dfs(i, deep+1);
		}
	}
	if (tag == 0) {
		paths.push_back(deep);
		return;
	}
}