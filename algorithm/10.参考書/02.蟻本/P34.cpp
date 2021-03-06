#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

bool dfs(int i, int sum) {
    if (i == n) return sum == k;

    // a[i]を使わない場合
    if (dfs(i+1, sum)) return true;

    // a[i]を使う場合
    if (dfs(i+1, sum+a[i])) return true;
    return false;
}

// 以下省略