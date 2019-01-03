#include <iostream>
using namespace std;

class Hash{
public:
	int data[10000];
	int length;
	int count;

	Hash(int n, int m) {
		for (int i = 0; i < m; ++i) {
			data[i] = 10001;
		}
		count = n;
		length = m;
	}

	Hash & create() {
		for (int i = 0; i < count; ++i) {
			int key;
			cin >> key;
			int pos = key % length;
			
			int tag = 0;
			for (int j = pos; j < length; ++j) {
				if (data[j] == 10001) {
					data[j] = key;
					tag = 1;
					break;
				}
			}
			if (tag == 0) {
				for (int j = 0; j < pos; ++j) {
					if (data[j] == 10001) {
						data[j] = key;
						break;
					}
				}
			}
		}
		return *this;
	}

	void print() {
		for (int i = 0; i < length; ++i) {
			if (data[i] != 10001) {
				cout << i << "#" << data[i] << '\n';
			}
			else {
				cout << i << "#NULL\n";
			}
		}
	}
};


int main() {
	int n,m;
	cin >> n >> m;
	Hash hash(n,m);
	hash.create();
	hash.print();
}
