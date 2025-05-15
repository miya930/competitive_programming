#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

vector<vector<ll>> dp(20, vector<ll>(100000, 0));

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) cin >> d[i][j];
    }

    for (int i = 0; i < n/2; i++) {
        for (int bits = 0; bits < 1<<n; bits++) {
            vector<int> ns;
            for (int j = 0; j < n; j++) {
                if (((bits>>j) & 1) != true) ns.push_back(j);
            }
            int m = ns.size();
            if (m < 2) continue;
            for (int j = 0; j < m; j++) {
                for (int k = j+1; k < m; k++) {
                    int jj = ns[j];
                    int kk = ns[k];
                    int kkk = kk - jj - 1;
                    int cost = d[jj][kkk];
                    int nb = bits | (1 << jj);
                    nb |= (1 << kk);
                    dp[i+1][nb] = max(dp[i+1][nb], dp[i][bits] + cost);
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int bits = 0; bits < 1 << n; bits++) {
            ans = max(ans, dp[i][bits]);
        }
    }
    cout << ans << endl;
    return 0;
}
