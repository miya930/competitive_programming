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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    // 横方向累積和
    vector<vector<int>> doyoko(h, vector<int>(w+1, 0)), ciryoko(h, vector<int>(w+1, 0)), xyoko(h, vector<int>(w+1, 0));
    vector<vector<int>> dotate(w, vector<int>(h+1, 0)), cirtate(w, vector<int>(h+1, 0)), xtate(w, vector<int>(h+1, 0));
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] == '.') {
                doyoko[i][j+1] = doyoko[i][j] + 1;
                ciryoko[i][j+1] = ciryoko[i][j];
                xyoko[i][j+1] = xyoko[i][j];
            } else if (s[i][j] == 'o') {
                doyoko[i][j+1] = doyoko[i][j];
                ciryoko[i][j+1] = ciryoko[i][j] + 1;
                xyoko[i][j+1] = xyoko[i][j];
            } else {
                xyoko[i][j+1] = xyoko[i][j] + 1;
            }
        }
    }
    rep(i, 0, w) {
        rep(j, 0, h) {
            if (s[j][i] == '.') {
                dotate[i][j+1] = dotate[i][j] + 1;
                cirtate[i][j+1] = cirtate[i][j];
                xtate[i][j+1] = xtate[i][j];
            } else if (s[j][i] == 'o') {
                dotate[i][j+1] = dotate[i][j];
                cirtate[i][j+1] = cirtate[i][j] + 1;
                xtate[i][j+1] = xtate[i][j];
            } else {
                xtate[i][j+1] = xtate[i][j] + 1;
            }
        }
    }

    int ans = inf;
    // yoko
    rep(i, 0, h) {
        rep(j, 0, w-k+1) {
            if (j+k > w) continue;
            if (xyoko[i][j+k] - xyoko[i][j] > 0) continue;
            int dtmp = doyoko[i][j+k] - doyoko[i][j];
            int ctmp = ciryoko[i][j+k] - ciryoko[i][j];
            int t = dtmp + ctmp;
            if (t == k) {
                ans = min(ans, dtmp);
            }

        }
    }
    rep(i, 0, w) {
        rep(j, 0, h-k+1) {
            if (j+k > h) continue;
            if (xtate[i][j+k] - xtate[i][j] > 0) continue;
            int dtmp = dotate[i][j+k] - dotate[i][j];
            int ctmp = cirtate[i][j+k] - cirtate[i][j];
            int t = dtmp + ctmp;
            if (t == k) {
                ans = min(ans, dtmp);
            }            
        }
    }
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
