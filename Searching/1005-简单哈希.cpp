#include <iostream>
#include <vector>
using namespace std;

struct node{
	int val;
	node *next;

	node() {
		val = 0;
		next = NULL;
	}
};

class Hash{
public:
	node * pos[13];

	Hash() {
		for (int i = 0; i < 13; ++i) {
			pos[i] = NULL;
		}
	}

	void create(int n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			node *p = new node;
			p->val = arr[i];
			int index = arr[i] % 13;
			if (pos[index] == NULL) {
				pos[index] = p;
			} 
			else {
				node *temp = pos[index];
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = p;
			}
		}
	}

	void show() {
		for (int i = 0; i < 13; ++i) {
			cout << i << '#';
			if (pos[i] == NULL) {
				cout << "NULL";
			} else {
				node * p = pos[i];
				cout << p->val;
				while (p->next != NULL) {
					cout << ' ' << p->next->val;
					p = p->next;	
				}
				delete p;
			}
			cout << '\n';
		}
	}
};

int main() {
	int n;

	while (cin >> n) {
		if (n==0) break;
		Hash hash;
		hash.create(n);
		hash.show();
	}
}