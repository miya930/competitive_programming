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
    ll n, m;
    cin >> n >> m;
    map<int, ll> slope;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        slope[(a+b)%n]++;
    }
    ll ans = m*(m-1)/2;
    for (auto v : slope) {
        ll tmp = v.second * (v.second - 1) / 2;
        ans -= tmp;
    }
    cout << ans << endl;

    return 0;
}
