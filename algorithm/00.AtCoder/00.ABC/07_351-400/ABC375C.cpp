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
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<char>> ans(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = min({i+1, j+1, n-i,n-j});
            int ni = i, nj = j;
            for (int k = 0; k < d%4; k++) {
                int ti = nj;
                int tj = n - 1 - ni;
                ni = ti;
                nj = tj;
            }
            ans[ni][nj] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
