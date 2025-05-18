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

int calc_dig(ll n) {
    int ret = 1;
    while(n > 0) {
        ret += 1;
        n /= 10;
    }
    return ret;
}

ll get_val(int n) {
    ll ret = 1;
    rep(i, 0, n) {
        ret *= 10;
    }
    return ret;
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll mul = 1;
    rep(i, 0, n) {
        ll tmp = (get_val(k)+a[i]-1) / a[i];
        if (tmp <= mul) {
            mul = 1;
        } else {
            mul *= a[i];
        }
    }
    cout << mul << endl;

    return 0;
}
