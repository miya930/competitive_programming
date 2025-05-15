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
    int n, m;
    n = 3;
    vector<string> s(n);
    cin >> m;
    rep(i, 0, n) cin >> s[i];

    int ans = inf;
    rep(x, 0, m) {
        int t = s[0][x];
        rep(y, 0, m) {
            rep(z, 0, m) {
                int tmp;
                if (t == s[1][y] && t == s[2][z]) {
                    if (x == y && x == z) {
                        tmp = x + 2*m;
                        ans = min(ans, tmp);
                    } else if (x == y || x == z) {
                        tmp = x + m;
                        ans = min(ans, tmp);
                    } else if (z == y) {
                        tmp = y + m;
                        ans = min(ans, tmp);
                    } else {
                        tmp = max({x, y, z});
                        ans = min(ans, tmp);
                    }
                }
            }
        }
    }
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
