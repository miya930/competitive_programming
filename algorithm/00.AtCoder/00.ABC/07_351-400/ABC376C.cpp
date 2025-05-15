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
int n;
vector<ll> a,b;

bool check(ll x) {
    vector<ll> bb = b;
    bb.push_back(x);
    sort(bb.begin(), bb.end());
    bool ng = false;
    for (int i = 0; i < n; i++) {
        if (a[i] > bb[i]) ng = true;
    }
    if (ng) return false;
    else return true;
}

int main()
{
    cin >> n;
    a.resize(n);
    b.resize(n-1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l = 0, r = 1e9+1;
    while(r-l>1){
        ll mid = (r+l)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (r == 1e9+1) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}
