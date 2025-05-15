#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };
const ll mod = 998244353;

int main()
{
    int Q, k;
    cin >> Q >> k;
    vector<ll> dp(k+100, 0);
    dp[0] = 1;
    rep(q, 0, Q) {
        char c;
        int val;
        cin >> c >> val;

        if (c == '+') {
            for (int i = k; i >= 0; i--) {
                if (i + val <= k && dp[i] >= 1) {
                    dp[i+val] += dp[i];
                    dp[i+val] %= mod;
                }
            }
        } else {
            rep(i, 0, k+1) {
                if (i + val <= k && dp[i] >= 1 && dp[i+val] >= 1) {
                    dp[i+val] -= dp[i];
                    dp[i+val] = (dp[i+val] + mod) % mod;
                }                
            }
        }
        if (dp[k] == -1) cout << 0 << endl;
        else cout << dp[k] << endl;
    }

    return 0;
}
