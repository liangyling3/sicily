#include<iostream>
using namespace std;
struct node{
	int key;
	int height;
	node* left;
	node* right;
};
int getheight(node* temp) {
	if (temp == NULL) return 0;
	else return temp->height;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
 
//顺时针旋 
node* LL(node* root) {
	node* p = root->left;
	root->left = p->right;
	p->right = root;
	p->height = max(getheight(root->left), getheight(root->right))+1;
	root->height = max(getheight(root->left), getheight(root->right))+1;
	return p;
}
 
//逆时针旋 
node* RR(node* root) {
	node* p = root->right;
	root->right = p->left;
	p->left = root;
	p->height = max(getheight(root->left), getheight(root->right))+1;
	root->height = max(getheight(root->left), getheight(root->right))+1;
	return p;
}
 
node* LR(node* root) {
	root->left = RR(root->left);  
    return LL(root);
}
 
node* RL(node* root) {
	root->right = LL(root->right);
	return RR(root);
}
 
void insert(node* &root, int value) {
	if (root == NULL) {
		root = new node;
		root->key = value;
		root->height = 1;
		root->left = NULL;
		root->right = NULL;
	} else {
		if (value > root->key) {
			insert(root->right, value);
			if (getheight(root->right) - getheight(root->left) > 1) {
				if (value > root->right->key) root = RR(root);  
                else root = RL(root);
			}
		} else if (value < root->key) {
			insert(root->left, value);
			if (getheight(root->left) - getheight(root->right) > 1) {
				if (value < root->left->key) root = LL(root);
            	else root = LR(root);
			}
		}
	}
	root->height = max(getheight(root->right), getheight(root->left)) + 1;
}
 
void dele(node* root) {
	if (root != NULL) {
		dele(root->left);
		dele(root->right);
		delete root;
		root = NULL;
	}
}
 
void preorder(node* root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
 
int main() {
	int num;
	cin >> num;
	while(num--) {
		int count, temp;
		cin >> count;
		node* now = NULL;
		while(count--) {
			cin >> temp;
			insert(now, temp);
		}
		preorder(now);
		cout << endl;
		dele(now);
	}
}
