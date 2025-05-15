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
    vector<int> x(m);
    rep(i, 0, m) {
        cin >> x[i];
        x[i]--;
    }
    vector<ll> v(n+1);
    auto dist = [&](int from, int to) {
        if (from <= to) return to - from;
        else return to + n - from;
    };
    auto add = [&](int from, int to, int num) {
        if (from <= to) {
            v[from] += num;
            v[to] -= num;
        } else {
            v[from] += num;
            v[n] -= num;
            v[0] += num;
            v[to] -= num;
        }
    };
    for (int i = 0; i < m-1; i++) {
        add(x[i], x[i+1], dist(x[i+1], x[i]));
        add(x[i+1], x[i], dist(x[i], x[i+1]));
    }
    ll ans = infl;
    rep(i, 0, n) {
        v[i+1] += v[i];
        ans = min(ans, v[i]);
    }
    cout << ans << endl;

    return 0;
}
