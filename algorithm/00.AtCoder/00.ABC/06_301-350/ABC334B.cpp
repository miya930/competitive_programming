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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    
    ll ans = 0;
    if (a < l) {
        ll fi  = a + (l - a + m - 1) / m * m;
        ans += (r - fi) / m;
        if (ans > 0) ans++;
    } else if (l <= a && a <= r) {
        ans++;
        ans += (a - l) / m;
        ans += (r - a) / m;
    } else {
        ll la = a - (a - r + m - 1) / m * m;
        ans += (la - l) / m;
        if (ans > 0) ans++;
    }
    if (l == r) {
        if (abs(l - a) % m == 0) {
            ans = 1;
        }
    }

    cout << ans << endl;
    return 0;
}
