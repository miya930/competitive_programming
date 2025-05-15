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


int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> sum(26, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[j][i+1] = sum[j][i];
        }
        sum[s[i] - 'A'][i+1]++;
    }
    ll ans = 0;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 26; i++) {
            ll l = sum[i][j];
            ll r = sum[i][n] - sum[i][j+1];
            ans += l * r;
        }
    }

    cout << ans << endl;
    return 0;
}
