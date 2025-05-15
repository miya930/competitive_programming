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
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m), c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> sum(m+1, 0);
    rep(i, 0, m) sum[i+1] = sum[i] + b[i];
    rep(i, 0, n) {
        c[i] = p - a[i];
    }

    ll ans = 0;
    rep(i, 0, n) {
        if (c[i] <= 0) {
            ans += p * m;
            continue;
        }

        auto itr = lower_bound(b.begin(), b.end(), c[i]);
        if (itr == b.end()) {
            ll idx = itr - b.begin();
            ans += a[i] * m;
            ans += (sum[m] - sum[0]);
        } else {
            ll idx = itr - b.begin();
            ans += p * (m - idx);
            ans += a[i] * idx;
            ans += (sum[idx] - sum[0]);
        }
    }
    cout << ans << endl;
    return 0;
}
