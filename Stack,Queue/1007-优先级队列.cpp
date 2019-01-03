#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
 
class node {
  public:
    int pos;
    int pri;
};
 
int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n,m;
        // 原来还可以这样操作！
        node e[100];
        queue<node> q;
        int maxPri = 0;
        int countPri[10] = {0};			// 统计各个优先级出现的个数
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> e[i].pri;
            e[i].pos = i;
            q.push(e[i]);

            if(e[i].pri < maxPri) {		// 找出最大的优先级
                maxPri = e[i].pri;
            }
            countPri[e[i].pri]++;
        }
 
        int count = 0;
        while(1) {
            node current = q.front();
            if (current.pri == maxPri) {
                count ++;
                countPri[maxPri] --;
                q.pop();

                if(current.pos == m)
                    break;

                while(maxPri > 0 && countPri[maxPri] == 0) {
                    maxPri--;
                }
            }
            else {
                node temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
 
        cout << count << endl;
    }
    return 0;
}                                 
