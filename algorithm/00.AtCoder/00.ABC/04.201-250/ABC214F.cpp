#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

vector<vector<int> > calcNext(string s) {
    int n = s.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][s[i]-'a'] = i;
    }
    return res;
}

void add(ll &a, ll b) {
    a += b;
    a %= mod;
}

int main()
{
    string s; cin >> s;
    int n = (int)s.size();
    vector<ll> dp(n+1, 0);

    vector<vector<int> > next = calcNext(s);
    dp[0] = 1;
    for (int i = 0; i < 26; ++i) add(dp[next[0][i]+1], dp[0]);

    for(int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (next[i][j] >= n) continue;
            if (next[i][j] == i+1) {
                if (next[i][j] >= n) continue;
                add(dp[next[i+1][j]+1], dp[i]);
            } else {
                add(dp[next[i+1][j]+1], dp[i]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i) add(ans, dp[i]);
    cout << ans - 1 << endl;
}
