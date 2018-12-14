#include <bits/stdc++.h>
using namespace std;

int n, k, size = 0;
vector<int> nums(10000001);
bitset<20000001> exist(0);

int findk(int left, int right, int pos);
void exchange(int posA, int posB);

int main() {
    int tmp, bitpos;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        bitpos = tmp + 10000000;
        if (!exist.test(bitpos)) {
            exist.set(bitpos);
            nums[size++] = tmp;
        }
    }

    printf("%d\n", findk(0, size - 1, k));
    return 0;
}

void exchange(int posA, int posB) {
    int tmp = nums[posA];
    nums[posA] = nums[posB];
    nums[posB] = tmp;
}

int findk(int left, int right, int pos) {
    int main = nums[left];
    int i = left + 1, j = right;

    while (i <= j) {
        while (nums[i] > main) i++;
        while (nums[j] < main) j--;
        if (i < j) exchange(i, j);
    }

    exchange(left, j);
    int length = j - left + 1;
    if (length == pos) return nums[j];
    else if (length > pos) return findk(left, j - 1, pos);
    else return findk(j + 1, right, pos - length);
}