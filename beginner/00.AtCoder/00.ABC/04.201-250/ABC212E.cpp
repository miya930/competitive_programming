#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int> > vec(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) vec[i].push_back(i);


    vector<vector<ll> > dp(k + 1, vector<ll>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < k; ++i) {
        ll tot = 0;
        for (int j = 0; j < n; ++j) {
            tot += dp[i][j];
            tot %= mod;
        }
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j] += tot;
            for (auto v : vec[j]) {
                dp[i + 1][j] -= dp[i][v];
                dp[i + 1][j] = (dp[i + 1][j] + mod) % mod;
            }
        }
    }
    cout << dp[k][0] << endl;
}
