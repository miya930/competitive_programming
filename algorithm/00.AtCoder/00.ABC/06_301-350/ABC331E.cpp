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
    int n, m, l;
    cin >> n >> m >> l;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vector<ll> c(l), d(l);
    vector<map<ll, int>> vec(n);
    vector<ll> aa = a, bb = b;
    sort(aa.rbegin(), aa.rend()); sort(bb.rbegin(), bb.rend());
    rep(i, 0, l) {
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
        vec[c[i]][b[d[i]]]++;
    }
    ll ans = 0;
    rep(i, 0, n) {
        ll tmp = a[i];
        rep(j, 0, m) {
            if (vec[i].count(bb[j]) == 1) {
                continue;
            }
            tmp += bb[j];
            break;
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;

    return 0;
}
