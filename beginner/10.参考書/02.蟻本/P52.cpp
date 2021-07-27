#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, W;

// ナップサック問題の愚直解 (再帰関数を使用して解く)
int rec(int i, int j) {
    int res;
    if (i == n) {
        // もう品物は残っていない
        res = 0;
    } else if (j < w[i]) {
        // この品物は入らない
        res = rec(i + i, j);
    } else {
        // 入れない場合と入れる場合を両方試す
        res = max(rec(i + 1, j), rec(i + 1, j - w[i])) + v[i];
    }
    return res;
}

void solve() {
    print("%d\n", rec(0, W));
}

int main()
{
    cin >> n >> W;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];

}
