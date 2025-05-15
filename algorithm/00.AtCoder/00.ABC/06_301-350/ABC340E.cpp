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
    int n, m;
    cin >> n >> m;

    fenwick_tree<ll> d(n+1);
    auto add = [&](int l, int r, ll x) {
        d.add(l, x);
        d.add(r, -x);
    };
    rep(i, 0, n) {
        int a;
        cin >> a;
        add(i, i+1, a);
    }
    rep(i, 0, m) {
        int b;
        cin >> b;
        ll x = d.sum(0, b+1);
        add(b, b+1, -x);

        ll c = x/n; x %= n;
        add(0, n, c);
        b++;

        if (b+x < n) {
            add(b, b+x, 1);
        } else {
            add(b, n, 1);
            add(0, b+x-n, 1);
        }
    }

    rep(i, 0, n) {
        ll ans = d.sum(0, i+1);
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
