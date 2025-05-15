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
    int n,m;
    cin >> n >> m;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<vector<int>> a(m, vector<int>(20));
    map<int, vector<int>> can;
    rep(i, 0, m) {
        int k; cin >> k;
        rep(j, 0, k) {
            cin >> a[i][j];
            a[i][j]--;
            can[a[i][j]].push_back(i);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     if (can.count(i)) {
    //         sort(can[i].begin(), can[i].end());
    //         can[i].erase(unique(can[i].begin(), can[i].end()), can[i].end());
    //     }
    // }
    ll ans = infl;
    for (int i = 0; i < 1<<n; i++) {
        for (int l = 0; l < 1<<n; l++) {
            vector<int> seen(m, 0);
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    if (can.count(j) == 0) continue;
                    vector<int> animals = can[j];
                    for (auto v : animals) {
                        seen[v]++;
                    }
                    sum += c[j];
                }
            }
            for (int j = 0; j < n; j++) {
                if (l & (1<<j)) {
                    if (can.count(j) == 0) continue;
                    vector<int> animals = can[j];
                    for (auto v : animals) {
                        seen[v]++;
                    }
                    sum += c[j];
                }
            }
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (seen[j] < 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
