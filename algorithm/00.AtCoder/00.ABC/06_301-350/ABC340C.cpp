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

map<ll, ll> mp;

ll func(ll n) {

    if (n == 1) return 0;
    if (mp.count(n) > 0) return mp[n];

    ll l = n/2;
    ll r = (n+1)/2;

    ll lcnt = l, rcnt = r;

    if (mp.count(l) == 0) lcnt += func(l);
    else lcnt += mp[l];
    if (mp.count(r) == 0) rcnt += func(r);
    else rcnt += mp[r];

    mp[n] = lcnt + rcnt;

    return mp[n];
}

int main()
{
    ll n;
    cin >> n;
    
    cout << func(n) << endl;

    return 0;
}
