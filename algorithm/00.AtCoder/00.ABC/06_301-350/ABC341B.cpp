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
    int n;
    cin >> n;
    vector<ll> a(n), s(n-1), t(n-1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) cin >> s[i] >> t[i];

    rep(i, 0, n-1) {
        ll d = a[i] / s[i];
        a[i+1] += (d * t[i]);
    }
    cout << a[n-1] << endl;

    return 0;
}
