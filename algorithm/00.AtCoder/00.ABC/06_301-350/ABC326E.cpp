#include <bits/stdc++.h>
#include <atcoder/modint>
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
using mint = modint998244353;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    mint ans = 0;
    mint p = (mint)1/n;

    rep(i, 0, n) {
        ans += p * a[i];
        p += p / n;
    }

    cout << ans.val() << endl;

    return 0;
}
