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

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;

    auto f = [&](ll v, ll d) -> ll {
        if (v > n) return 0;
        ll l = v, r = v;
        rep(i, 0, d) {
            l <<= 1;
            r = r << 1 | 1;
            if (l > n) return 0;
        }
        r = min(r, n);
        return r - l + 1;
    };

    ll ans = f(x, k);
    while(x > 1 && k >= 2) {
        ans += f(x^1, k-2);
        k--; x >>= 1;
    }
    if (k == 1 && x != 1) ans++;
    cout << ans << endl;

}

int main()
{
    int t;
    cin >> t;
    rep(i, 0, t) solve();

    return 0;
}
