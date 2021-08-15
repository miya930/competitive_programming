#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

vector<vector<int> > calcNext(const string &s){
    int n = (int)s.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][s[i]-'a'] = i;
    }
    return res;
}

void add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int> > next = calcNext(s);

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (next[i][j] >= n) continue;
            add(dp[next[i][j]+1], dp[i]);
        }
    }

    ll res = 0;
    for (int i = 0; i <= n; ++i) add(res, dp[i]);
    cout << res << endl;

}
