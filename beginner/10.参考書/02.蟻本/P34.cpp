#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

bool dfs(int i, int sum) {
    if (i == n) return sum == k;

    // a[i]���g��Ȃ��ꍇ
    if (dfs(i+1, sum)) return true;

    // a[i]���g���ꍇ
    if (dfs(i+1, sum+a[i])) return true;
    return false;
}

// �ȉ��ȗ�