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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    map<int,int> row, col;
    rep(i, 0, n) {
        int c = 0;
        rep(j, 0, n) {
            if (s[i][j] == 'o') c++;
        }
        row[i] = c;
    }
    rep(j, 0, n) {
        int r = 0;
        rep(i, 0, n) {
            if (s[i][j] == 'o') r++;
        }
        col[j] = r;
    }

    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (s[i][j] == 'o') {
                ans += (row[i]-1)*(col[j]-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
