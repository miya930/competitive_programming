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
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), w(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());

    int si = min(n, m);
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < si; i++) {
        if (w[i] >= 0) {
            ll tmp = w[i] + b[i];
            if (tmp >= 0) {
                sum += tmp;
            }
        } else {
            if (b[i] >= 0) {
                sum += b[i];
            } else {
                break;
            }
        }
        ans = max(ans, sum);
    }
    for (int i = si; i < n; i++) {
        if (b[i] >= 0) {
            sum += b[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
