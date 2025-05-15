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

vector<string> rotateVector2(vector<string> &s, int h, int w, int angle) {
    vector<string> ret = s;
    rep(i, 0, h) rep(j, 0, w) {
        if (angle == 90) {
            ret[j][w-i-1] = s[i][j];
        } else if (angle == 180) {
            ret[h-i-1][w-j-1] = s[i][j];
        } else if (angle == 270) {
            ret[w-j-1][i] = s[i][j];
        }
    }
    return ret;
}


int main()
{
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> t[i];
    int ans = inf;

    vector<int> rot;
    rot.push_back(0);
    rot.push_back(90);
    rot.push_back(180);
    rot.push_back(270);

    for (int i = 0; i < 4; i++) {
        int res = i;
        vector<string> s_rot = rotateVector2(s, n, n, rot[i]);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (s_rot[y][x] != t[y][x]) {
                    res++;
                }
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
