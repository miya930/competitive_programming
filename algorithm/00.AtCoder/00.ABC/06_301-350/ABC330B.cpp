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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, n) {
        ll y;
        if (l <= a[i] && a[i] <= r) {
            y = a[i];
        } else if (a[i] <= l) {
            y = l;
        } else {
            y = r;
        }
        cout << min(y, r) << " ";
    }
    cout << endl;

    return 0;
}
