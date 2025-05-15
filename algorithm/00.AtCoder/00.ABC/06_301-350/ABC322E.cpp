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

ll dp[110][10][10][10][10][10];

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> a(n, vector<int>(k));
    vector<ll> c(n);
    rep(i, 0, n) {
        cin >> c[i];
        rep(j, 0, k) cin >> a[i][j];
    }
    rep(i, 0, 110) {
        rep(x, 0, p+1) {
            rep(y, 0, p+1) {
                rep(z, 0, p+1) {
                    rep(v, 0, p+1) {
                        rep(w, 0, p+1) dp[i][x][y][z][v][w] = infl;
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0][0] = 0;
    rep(i, 0, n) {
        rep(x, 0, p+1) {
            rep(y, 0, p+1) {
                rep(z, 0, p+1) {
                    rep(v, 0, p+1) {
                        rep(w, 0, p+1) {
                            
                            rep(j, 0, k) {
                                if (dp[i][x][y][z][v][w] == infl) continue;
                                dp[i+1][x][y][z][v][w] = min(dp[i+1][x][y][z][v][w], dp[i][x][y][z][v][w]);
                                int j1,j2,j3,j4,j5;
                                if (k >= 1) j1 = min(p, x+a[i][0]);
                                if (k >= 2) j2 = min(p, y+a[i][1]);
                                else j2 = 0;
                                if (k >= 3) j3 = min(p, z+a[i][2]);
                                else j3 = 0;
                                if (k >= 4) j4 = min(p, v+a[i][3]);
                                else j4 = 0;
                                if (k >= 5) j5 = min(p, w+a[i][4]);
                                else j5 = 0;
                                dp[i+1][j1][j2][j3][j4][j5] = min(dp[i+1][j1][j2][j3][j4][j5], dp[i][x][y][z][v][w] + c[i]);                         
                            }
                        }
                    }
                }
            }
        }
    }
    int x = p, y = p, z = p, v = p, w = p;
    if (k <= 4) w = 0;
    if (k <= 3) v = 0;
    if (k <= 2) z = 0;
    if (k <= 1) y = 0;
    if (dp[n][x][y][z][v][w] == infl) cout << -1 << endl;
    else cout << dp[n][x][y][z][v][w] << endl;


    return 0;
}
