#include <iostream>
using namespace std;

int adj[101][101];
int isVisited[101];		// 标记访问
int kind[101][101];		// 存储边的类型：1-树边 2-后向边 3-前向边 4-横叉边

bool isAllVisited(int v) {
	for (int i = 1; i <= 101; ++i) {
		if (adj[v][i] and !isVisited[i])
			return 0;
	}
	return 1;
}

void dfs(int v) {
	if (!isVisited[v]) {
		isVisited[v] = 1;
		for (int i = 0; i < 101; ++i) {
			if (adj[v][i]) {
				if (!isVisited[i]) {
					kind[v][i] = 1;
					dfs(i);
				}
				else {
					if (!isAllVisited(i)) {
						kind[v][i] = 2;
						dfs(i);
					}
					else {
						if (v == 1) {
							kind[v][i] = 3;
						}
						else {
							kind[v][i] = 4;
						}
					}
				}
			}
		}
	}
}

void search(int vertex) {
	for (int i = 1; i <= vertex; ++i) {
		if (!isVisited[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			adj[i][j] = 0;
		}
	}

	int vertex, edge;
	cin >> vertex >> edge;
	for (int i = 0; i < edge; ++i) {
		int m, n;
		cin >> m >> n;
		adj[m][n] = 1;
	}

	search(vertex);

	int query;
	cin >> query;
	for (int i = 0; i < query; ++i) {
		int m, n;
		cin >> m >> n;
		if (kind[m][n] == 1) 
			cout << "edge (" << m << "," << n << ") is Tree Edge\n"; 
		else if (kind[m][n] == 2)
			cout << "edge (" << m << "," << n << ") is Back Edge\n";
		else if (kind[m][n] == 3)
			cout << "edge (" << m << "," << n << ") is Down Edge\n";
		else if (kind[m][n] == 4)
			cout << "edge (" << m << "," << n << ") is Cross Edge\n";
	}
}