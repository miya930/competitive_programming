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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    rep(i, 0, h) {
        rep(j, 0, w) cin >> a[i][j];
    }
    rep(i, 0, h) {
        rep(j, 0, w) cin >> b[i][j];
    }
    int ans = inf;
    vector<int> v1(h), v2(w);
    rep(i, 0, h) v1[i] = i;
    rep(i, 0, w) v2[i] = i;

    do {
        do {
            bool match = true;
            rep(i, 0, h) rep(j, 0, w) {
                int p = v1[i];
                int q = v2[j];
                if (a[p][q] != b[i][j]) match = false;
            }
            if (!match) continue;

            int t = 0;
            rep(i, 0, h) rep(j, i+1, h) {
                if (v1[i] > v1[j]) t++;
            }
            rep(i, 0, w) rep(j, i+1, w) {
                if (v2[i] > v2[j]) t++;
            }
            ans = min(ans, t);
        } while(next_permutation(v2.begin(), v2.end()));
    } while(next_permutation(v1.begin(), v1.end()));

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
