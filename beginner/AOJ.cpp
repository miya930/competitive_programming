#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

vector<vector<int> > calcNext(string s) {
    int n = s.size();
    vector<vector<int> > res(n+1, vector<ll>(26, n));
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
    string t = s;
    reverse(t.begin(), t.end());

    vector<vector<int> > ns = calcNext(s);
    vector<vector<int> > nt = calcNext(t);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 26;  ++k) {
                int ni = ns[i][k];
                int nj = nt[j][k];
                if (ni+nj+2>n) continue;
                add(dp[ni+1][nj+1], dp[i][j]);
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; i+j<= n; ++j) {
            int num = 1;
            for (int k = 0; k < 26; ++k) if (ns[i][k]+1+j<=n) ++num;
            res = (res + dp[i][j] * num % mod) % mod;
        }
    }
    cout << res - 1 << endl;
}
