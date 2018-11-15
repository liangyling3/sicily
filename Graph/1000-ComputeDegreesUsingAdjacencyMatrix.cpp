#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

typedef  struct {
	int arcs[MAX_SIZE][MAX_SIZE]; //adjacency matrix of the graph
	int vexnum;// number of vertices
	int arcnum;//number of edges

} AMGraph;

// returns a list of indegrees and outdegrees for all vertices
vector<pair<int, int> > degree(const AMGraph &g) {
	vector<pair<int, int> > result;
	for (int i = 0; i < g.vexnum; ++i) {
		pair<int, int> pair;
		pair.first = 0;
		pair.second = 0;
		result.push_back(pair);
	}
	for (int i = 0; i < g.vexnum; ++i) {
		for (int j = 0; j < g.vexnum; ++j) {
			if (g.arcs[i][j] != 0) {
				result[i].second ++;
				result[j].first ++;
			}
		}
	}
	return result;
}


 AMGraph mkAMGraph(const char * f) {
 	AMGraph g;
 	int size = f[0] - '0';
 	g.vexnum = size;
 	g.arcnum = 0;
 	for (int i = 0; i < size; ++i) {
 		for (int j = 0; j < size; ++j) {
 			if (f[i*size+j] != '0') {
 				g.arcnum ++;
 				g.arcs[i][j] = f[i*size+j] - '0';
 			}
 		}
 	}
 	return g;
 }

// 无法读取完整文件？？？？
 int main() {
 	ifstream infile;
 	infile.open("1000.txt");
 	if (!infile.is_open()) {
 		cout << "无法打开文件" << '\n';
 		return 0;
 	}
 	char num;
 	int count = 0;
 	while (infile >> num) {
 		char f[num*num+1];
 		f[0] = num;
 		for(int i = 0; i < num*num; ++i) {
 			infile >> f[i+1];
 		}
 		AMGraph g = mkAMGraph(f);
 		vector<pair<int, int> > vec = degree(g);
 		count ++;
 		cout << count;
 	}
 	infile.close();
 }