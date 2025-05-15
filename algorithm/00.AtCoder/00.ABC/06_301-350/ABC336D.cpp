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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> dpl(n+1, inf), dpr(n+1, inf);
    dpl[0] = 0;
    // left
    rep(i, 0, n) {
        dpl[i+1] = min(dpl[i]+1, a[i]);
    }
    // right
    reverse(a.begin(), a.end());
    dpr[0] = 0;
    rep(i, 0, n) {
        dpr[i+1] = min(dpr[i]+1, a[i]);
    }
    int ans = 0;
    rep(i, 1, n+1) {
        int t = min(dpl[i], dpr[n-i+1]);
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
