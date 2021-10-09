// https://atcoder.jp/contests/code-festival-2017-quala/submissions/me
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i <= n; ++i)

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool ans = false;
    rep(i, n) rep(j, m) {
        int temp = i * m + j * n - 2 * i * j;
        if (temp == k) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
