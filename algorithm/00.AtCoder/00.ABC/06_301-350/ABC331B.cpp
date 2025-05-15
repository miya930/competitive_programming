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
    ll n, s, m, l;
    cin >> n >> s >> m >> l;

    ll ans = infl;
    rep(i, 0, 110) {
        rep(j, 0, 110) {
            rep(k, 0, 110) {
                ll cnt = 6*i + 8*j + 12*k;
                if (cnt < n) continue;
                ll tmp = i * s + j * m + k * l;
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
