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
    ll d;
    cin >> d;
    vector<ll> vec;
    for (ll i = 1; i <= 1000000; i++) {
        vec.push_back(i*i);
    }
    int n = vec.size();
    ll ans = infl;
    for (ll i = 1; i <= 1000000; i++) {
        ll xs = i*i, ys;
        ll res = xs - d;
        if (res >= 0) {
            ys = 0;
            ans = min(ans, abs(xs+ys-d));
        } else {
            ys = sqrt(-res);
            ans = min(ans, abs(xs+ys*ys-d));
            ans = min(ans, abs(xs+(ys+1)*(ys+1)-d));
        }
    }
    cout << ans << endl;


    return 0;
}
