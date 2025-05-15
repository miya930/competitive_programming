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

int dis[60][60][60][60];

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    int sx1, sy1, sx2, sy2;
    int cnt = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (s[i][j] == 'P') {
                if (cnt == 0) {
                    sx1 = i;
                    sy1 = j;
                    cnt++;
                } else {
                    sx2 = i;
                    sy2 = j;
                }
            }
        }
    }

    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n) {
        dis[i][j][k][l] = inf;
    }
    queue<array<int,4>> que;
    dis[sx1][sy1][sx2][sy2] = 0;
    que.push({sx1, sy1, sx2, sy2});
    while(!que.empty()) {
        array<int,4> ar = que.front();
        que.pop();
        rep(i, 0, 4) {
            int nx1 = ar[0] + dx[i];
            int ny1 = ar[1] + dy[i];
            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || s[nx1][ny1] == '#') {
                nx1 = ar[0];
                ny1 = ar[1];
            }
            int nx2 = ar[2] + dx[i];
            int ny2 = ar[3] + dy[i];
            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || s[nx2][ny2] == '#') {
                nx2 = ar[2];
                ny2 = ar[3];
            }
            if (dis[nx1][ny1][nx2][ny2] == inf) {
                dis[nx1][ny1][nx2][ny2] = dis[ar[0]][ar[1]][ar[2]][ar[3]] + 1;
                que.push({nx1,ny1,nx2,ny2});
            }
        }
    }
    int ans = inf;
    rep(i, 0, n) rep(j, 0, n) ans = min(ans, dis[i][j][i][j]);
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
