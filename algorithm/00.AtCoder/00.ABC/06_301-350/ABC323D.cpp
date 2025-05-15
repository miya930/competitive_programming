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
    map<ll,ll> mp;
    rep(i, 0, n){
        ll s, c;
        cin >> s >> c;
        mp[s] = c;
    }

    ll ans = 0;
    for (auto x : mp) {
        ll t = x.first;
        ll div = x.second / 2;
        ll mod = x.second % 2;
        if (mod == 1) ans++;
        if (div > 0) {
            if (mp.count(2*t) > 0) mp[2*t] += div;
            else mp[2*t] = div;
        }
    }
    cout << ans << endl;
    return 0;
}
