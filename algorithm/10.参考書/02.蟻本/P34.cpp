#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

bool dfs(int i, int sum) {
    if (i == n) return sum == k;

    // a[i]‚ğg‚í‚È‚¢ê‡
    if (dfs(i+1, sum)) return true;

    // a[i]‚ğg‚¤ê‡
    if (dfs(i+1, sum+a[i])) return true;
    return false;
}

// ˆÈ‰ºÈ—ª