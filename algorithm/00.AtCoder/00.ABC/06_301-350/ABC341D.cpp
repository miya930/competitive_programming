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

ll n, m, k;
ll ans = 0;
ll a, b;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

bool check(ll mid) {
    ll acnt = mid / a;
    ll bcnt = mid / b;
    ll l = a*b/gcd(a, b);
    ll abcnt = mid / l;
    ll sum = acnt + bcnt - 2*abcnt;
    if (sum > k) return true;
    else return false;
}

int main()
{
    cin >> n >> m >> k;

    a = min(n, m);
    b = max(n, m);
    ll l = 0, r = max(n,m)*k*5;
    while(r - l > 1) {
        ll mid = (r+l)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    ll bcnt = l / b;
    ll acnt = l / a;
    l = max(bcnt * b, acnt * a);

    ll lc = a*b/gcd(a, b);
    
    if (l%(lc) == 0) {
        ans = max(l-a, l-b);
    } else {
        ans = l;
    }
    cout << ans << endl;

    return 0;
}
