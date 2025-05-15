#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

mint dp[200100];

int main()
{
    ll n, p;
    cin >> n >> p;
    mint s = p;
    mint prob = mint(p) / 100;
    mint inv = 1 - prob;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[max(0, i-2)] * prob + dp[i-1] * inv + 1;
    }
    cout << dp[n].val() << endl;
    return 0;
}
