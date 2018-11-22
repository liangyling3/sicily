#include <iostream>
#include <queue>
using namespace std;

int adj[1001][1001];
int isVisited[1001];
int dis[1001];			// 距离

void search(int vertex);
void bfs(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int vertex, edge;
	cin >> vertex >> edge;
	for (int i = 0; i < edge; ++i) {
		int m, n;
		cin >> m >> n;
		adj[m][n] = 1;
		adj[n][m] = 1;
	}

	for (int i = 1; i <= vertex; ++i) {	// 初始化数组
		isVisited[i] = 0;
		dis[i] = 0;
	}

	search(vertex);
	for (int i = 1; i <= vertex; ++i) {
		cout << dis[i] << ' ';
	}
	cout << '\n';
}

void search(int vertex) {
	bfs(1);
	for (int i = 1; i <= vertex; ++i) {
		if (!isVisited[i]) {
			dis[i] = -1;
		}
	}
}

void bfs(int v) {
	queue<int> queue;
	if (!isVisited[v]) {
		isVisited[v] = 1;
		queue.push(v);
		
		while (!queue.empty()) {
			v = queue.front();
			queue.pop();

			for (int i = 1; i <= 1000; ++i) {
				if (adj[v][i] and !isVisited[i]) {
					dis[i] = dis[v] + 1;
					isVisited[i] = 1;
					queue.push(i);
				}
			}
		}
	}
}