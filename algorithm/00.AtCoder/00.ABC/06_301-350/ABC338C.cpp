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
    vector<ll> q(n), a(n), b(n);
    rep(i, 0, n) cin >> q[i];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll ans = 0;
    rep(x, 0, 1000001) {
        bool isng = false;
        rep(i, 0, n) {
            ll res = q[i] - a[i]*(ll)x;
            if (res < 0) isng = true;
            if (isng) break;
        }
        if (isng) continue;

        ll ymin = infl;
        rep(i, 0, n) {
            ll res = q[i] - a[i]*(ll)x;
            if (b[i] != 0) ymin = min(ymin, res/b[i]);
        }
        ans = max(ans, x+ymin);
    } 
    cout << ans << endl;

    return 0;
}
