#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class node {
  public:
  	char elem;
  	int weight;
  	string code;
  	node * left;
  	node * right;
  	node(char c, int w):elem(c), weight(w), code(""), left(NULL), right(NULL){}
};

bool cmp(const node &n1, const node &n2) {
	return n1.weight > n2.weight;
}

ostream & operator << (ostream & out, vector<node> &vec) {
	int len = vec.size();
	for (int i = 0; i < len; ++i) {
		out << vec[i].elem << ' ';
		out << vec[i].weight << ' ';
		out << vec[i].code << '\n';
	}
	return out;
}


void HuffmanCoding(vector<node> &letters) {
	sort(vec.begin(), vec.end(), cmp); 
	int len = letters.size();
	for (int i = len-1; i >= 0; --i) {}
}

vector<node> countTimes(const vector<char> &letters) {
	vector<node> result;
	int len = letters.size();
	for (int i = 0; i < len; ++i) {
		int tag = 0;
		for (int j = 0; j < result.size(); ++j) {
			if (letters[i] == result[j].elem) {
				tag = 1;
				result[j].weight ++;
			}
		}
		if (tag == 0) {
			node temp(letters[i], 1);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	cin >> size;
	vector<char> letters;
	for (int i = 0; i < size; ++i) {
		char c;
		cin >> c;
		letters.push_back(c);
	}
	vector<node> result = countTimes(letters);
	HuffmanCoding(result);
	cout << result;
}