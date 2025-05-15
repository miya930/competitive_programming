#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };
using mint = modint998244353;

vector<vector<int>> gro(2000, vector<int>(1200, -1));

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int g = 0;
    rep(x, 0, h) {
        rep (y, 0, w) {
            if (gro[x][y] != -1) continue;
            if (s[x][y] == '.') continue;
            gro[x][y] = g;
            queue<pair<int,int>> que;
            que.push(make_pair(x, y));
            while(!que.empty()) {
                int vx = que.front().first;
                int vy = que.front().second;
                que.pop();

                rep(i, 0, 4) {
                    int nx = vx + dx[i];
                    int ny = vy + dy[i];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (s[nx][ny] == '.' || gro[nx][ny] != -1) continue;

                    gro[nx][ny] = g;
                    que.push(make_pair(nx, ny));
                }
            }

            g++;
        }
    }

    int mag = g;
    mint ans = 0;
    mint red = 0;
    rep(x, 0, h) {
        rep(y, 0, w) {
            if (s[x][y] != '.') continue;
            red++;
            set<int> st;
            rep(i, 0, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (gro[nx][ny] != -1) st.insert(gro[nx][ny]);
            }
            ans += (g - (st.size() - 1));
        }
    }
    ans /= red;
    cout << ans.val() << endl;
    return 0;
}
