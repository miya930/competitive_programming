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

vector<ll> l;
ll n, m;
bool check(ll val) {
    ll cnt = 1;
    ll cur = l[0] + 1;
    rep(i, 1, n) {
        if (cur + l[i] > val) {
            cnt++;
            cur = l[i] + 1;
        } else {
            cur += (l[i]+1);
        }
    }
    if (cnt <= m) return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    l.resize(n);
    rep(i, 0, n) cin >> l[i];

    ll lef = 0, r = 0;
    rep(i, 0, n) {
        lef = max(lef, l[i]);
        r += (l[i] + 1);
    }
    lef--;
    while(r - lef > 1LL) {
        ll mid = (r + lef) / 2LL;
        if (check(mid)) r = mid;
        else lef = mid;
    }
    cout << r << endl;
    return 0;
}
