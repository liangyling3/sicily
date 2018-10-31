/*
Description
	Binary trees are a common data structure in computer science. In this problem we will look at an infinite binary tree where the nodes contain a pair of integers. The tree is constructed like this:
		The root contains the pair (1, 1).
		If a node contains (a, b) then its left child contains (a + b, b) and its right child (a, a + b)

Problem 
	Given the contents (a, b) of some node of the binary tree described above, suppose you are walking from the root of the tree to the given node along the shortest possible path. Can you find out how often you have to go to a left child and how often to a right child?

Input
	The first line contains the number of scenarios. 
	Every scenario consists of a single line containing two integers i and j (1 <= i, j <= 2*109) that represent a node (i, j). You can assume that this is a valid node in the binary tree described above.

Output
	The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing two numbers l and r separated by a single space, where l is how often you have to go left and r is how often you have to go right when traversing the tree from the root to the node given in the input. Print an empty line after every scenario.

Sample Input Copy
	3
	42 1
	3 4
	17 73
Sample Output Copy
	Scenario #1:
	41 0
	Scenario #2:
	2 1
	Scenario #3:
	4 6
*/

#include <iostream>
using namespace std;

class Path {
  public:
  	bool isValid;
  	int countLeft;
  	int countRight;

  	Path() {
  		isValid = true;
  		countLeft = 0;
  		countRight = 0;
  	}
};

Path calculate(int x, int y) {
	if (x == 1 and y == 1) {
		Path temp;
		return temp;
	}
	if (x < 1 or y < 1) {
		Path temp;
		temp.isValid = false;
		return temp;
	}
	Path left = calculate(x-y, y);
	Path right = calculate(x, y-x);

	if (left.isValid == 1) {
		left.countLeft ++;
		return left;
	} 
	else if (right.isValid == 1) {
		right.countRight ++;
		return right;
	}
	else {
		Path temp;
		temp.isValid = 0;
		return temp;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int size;
	cin >> size;
	for (int i = 0; i < size; ++i ) {
		int x, y;
		cin >> x >> y;

		Path result = calculate(x, y);
		cout << "Scenario #" << i+1 << ":\n";
		cout << result.countLeft << ' ' << result.countRight << '\n';
	}
}