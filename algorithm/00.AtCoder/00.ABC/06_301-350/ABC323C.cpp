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
    vector<int> a(m);
    vector<string> s(n);
    rep(i, 0, m) cin >> a[i];
    rep(i, 0, n) cin >> s[i];

    ll ma = -1;
    ll num = 0;
    vector<vector<ll>> vec(n);
    vector<ll> score(n, 0);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (s[i][j] == 'x') {
                vec[i].push_back(a[j]);
            } else {
                score[i] += a[j];
            }
        }
        sort(vec[i].rbegin(), vec[i].rend());
        if (ma < score[i]) {
            ma = max(ma, score[i]);
        }
    }
    rep(i, 0, n) score[i] += (i + 1);

    rep(i, 0, n) {
        int ans = 0;
        vector<ll> sc = score;
        while(1) {
            bool ng = false;
            rep(j, 0, n) {
                if (i == j) continue;
                if (sc[i] <= score[j]) ng = true;
            }
            if (!ng) {
                cout << ans << endl;
                break;
            }
            sc[i] += (vec[i][ans]);
            ans++;
        }
    }

    return 0;
}
