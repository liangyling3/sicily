#include<iostream>
#include<queue>
#include<vector>
#define M 10 //最多的列数
using namespace std;
 
struct node {
	int index;
	int priority;
};
 
struct cmp1 {
	bool operator()(node &n1, node &n2) {
		return n1.priority > n2.priority;//"小"的优先
	}
};
priority_queue<node, vector<node>, cmp1> seq;
 
struct entry {
	int index;
	int column[M];
};
 
struct cmp2 {
	bool operator()(entry &e1, entry &e2) {
		priority_queue<node, vector<node>, cmp1> original = seq;
		while(!original.empty()) {
			if(e1.column[original.top().index] != e2.column[original.top().index]) {
				return e1.column[original.top().index] > e2.column[original.top().index];//小的在前
			}
			else {
				original.pop();
			}
		}
		// 两个元素完全一致
		return e1.index > e2.index;		// 小的在前
	}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int testNum;
	cin >> testNum;
	while(testNum--) {
		int entryNum, columnNum;
		cin >> entryNum >> columnNum;
		vector<entry> v;
		for(int i = 0; i < entryNum; i++) {
			entry temp;
			for(int j = 0; j < columnNum; j++) {
				cin >> temp.column[j];
			}
			temp.index = i;
			v.push_back(temp);
		}
 
		int queryNum;
		cin >> queryNum;
		for(int i = 0; i < queryNum; i++) {
			while(!seq.empty()) {
				seq.pop();		// 清空
			}
			for(int j = 0; j < columnNum; j++) {
				node temp;
				cin >> temp.priority;
				temp.index = j;
				seq.push(temp);
			}
			priority_queue<entry, vector<entry>, cmp2>	Q(v.begin(), v.end());
			while(!Q.empty()) {
				cout << Q.top().index;
				if(Q.size() != 1)
					cout << " ";
				Q.pop();
			}
			cout << '\n';
		}
	}
}
