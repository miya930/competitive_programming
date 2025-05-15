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

vector<ll> ans(1000, 0);

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n-1), t(n-1);
    rep(i, 0, n-1) cin >> p[i] >> t[i];
    int Q;
    cin >> Q;
    rep(i, 0, 900) ans[i] = i + x;
    rep(i, 0, 861) {
        ll val = ans[i];
        rep(j, 0, n-1) {
            ll nex = (val+p[j]-1)/p[j] * p[j] + t[j];
            val = nex;
        }
        ans[i] = val;
    }
    rep(q, 0, Q) {
        ll tm;
        cin >> tm;
        cout << ans[tm%840] + y + tm - tm%840 << endl;
    }

    return 0;
}
