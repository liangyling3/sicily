// 对于完全二叉树，输入两个结点的位置，寻找他们最近的公共结点
// sample input:
// 		2				----测试样例个数
// 		10 4
//		7 13
// sample output:
//		2
//		3

#include <iostream>
using namespace std;

int getPosition(int x, int y) {
	if (x == y) return x;
	else if (x > y) return getPosition(x/2, y);
	else return getPosition(x, y/2);
}

int main() {
	ios::sync_with_stdio(false); // 解除绑定
	cin.tie(NULL);

	int size;
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int x, y;
		cin >> x >> y;
		cout << getPosition(x, y) << '\n';	// endl会刷新缓冲，减慢速度
	}
}