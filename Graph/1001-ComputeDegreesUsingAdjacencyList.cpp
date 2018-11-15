#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct ALGraph{
    vector<list<int> > adj; //adjacency list of the graph
    int vexnum;// number of vertices
    int arcnum;//number of edges
    //A  simple initialization.
    ALGraph(int n=0):vexnum(n){
        list<int> l;
        adj.resize(n,l);
    }
} ;

vector<pair<int, int> > degree(const ALGraph &g) {
	vector<pair<int,int> > result;
	for (int i = 0; i < g.vexnum; ++i) {
		pair<int, int> pair;
		pair.first = 0;
		pair.second = 0;
		result.push_back(pair);
	}
	for (int i = 0; i < g.vexnum; ++i) {
		int len = g.adj[i].size();
		result[i].second = len;
		for (auto it = g.adj[i].begin(); it != g.adj[i].end(); it++) {
			result[(*it)].first ++;
		}
	}
	return result;
}

 ALGraph mkALGraph(const char * f) {
 	ALGraph g;
 	int count = 0;
 	int size = f[count++];
 	g.vexnum = size;
 	for (int i = 0; i < size; ++i) {
 		list<int> list;
 		list.push_back(f[count++] - '0');
 		while (1) {
 			char c = f[count++];
 			if (c == '-') {
 				count ++;
 				break;
 			}
 			else {
 				list.push_back(c - '0');
 			}
 		}
 		g.adj.push_back(list);
 	}
 	return g;
 }

 int main() {

 }

