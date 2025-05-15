#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };
using mint = modint998244353;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];

    mint r = (mint)1/n;
    mint ans = 0;
    vector<mint> dp(x+1, 0);
    dp[0] = 1;
    if (t[0] > x) ans += dp[0]/(mint)n;
    rep(i, 1, x+1) {
        rep(j, 0, n) {
            if (t[j] <= i) dp[i] += dp[i-t[j]];
        }
        dp[i] *= r;
        if (i+t[0] > x) ans += dp[i]*r;
    }

    cout << ans.val() << endl;

    return 0;
}
