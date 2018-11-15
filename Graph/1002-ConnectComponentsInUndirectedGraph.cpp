#include <iostream>
#include <vector>
using namespace std;

#define maxVertex 1000

class Graph {
 public:
  	int size; // 顶点数
  	bool adjacency[maxVertex][maxVertex];

  	Graph(int numV, const vector<pair<int, int> > & edges) {
  		size = numV;
  		int len = edges.size();
  		for (int i = 0; i < len; ++i) {
  			adjacency[edges[i].first-1][edges[i].second-1] = 1;
  			adjacency[edges[i].second-1][edges[i].first-1] = 1;
  		}
  	}

 };


void dfs(int v, vector<int> & isVisited, const Graph & g) {
	isVisited[v] = 1;
	for (int i = 0; i < g.size; ++i) {
		if (g.adjacency[v][i] == 1 and isVisited[i] == 0)
			dfs(i, isVisited, g);
	}
}

int getConnectComponents(const Graph & g) {
 	int count = 0;
	vector<int> isVisited;			// 标记访问
	for (int i = 0; i < g.size; ++ i) {
		isVisited.push_back(0);
	}

	for (int i = 0; i < g.size; ++ i) {		
		if (isVisited[i] == 0) {
			dfs(i, isVisited, g);
			count++;
		}
	}
	return count;
}


int main() {
	int numV, numE;
	cin >> numV >> numE;
	vector<pair<int, int> > edges;
	for (int i = 0; i < numE; ++i) {
		pair<int, int> pair;
		cin >> pair.first;
		cin >> pair.second;
		edges.push_back(pair);
	}
	Graph g(numV, edges);
	cout << getConnectComponents(g) << '\n';
}