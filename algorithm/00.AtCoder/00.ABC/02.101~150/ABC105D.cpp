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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), sum(n+1, 0);
    map<int,ll> mp;
    mp[0] = 1;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) sum[i+1] = sum[i] + a[i];
    rep(i, 1, n+1) {
        mp[sum[i]%m]++;
    }
    ll ans = 0;
    for (auto v : mp) {
        ll nv = v.second;
        int val = v.first;
        ans += (nv * (nv-1) / 2);
    }

    cout << ans << endl;
    return 0;
}
