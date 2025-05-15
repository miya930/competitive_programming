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
int h, w, k;
vector<string> s;
vector<vector<bool>> seen;
int ans = 0;

void dfs(int x, int y, int cnt) {
    if (cnt >= k) {
        ans++;
        return;
    }
    seen[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#') continue;
        if (seen[nx][ny] != false) continue;
        dfs(nx, ny, cnt+1);
    }

    seen[x][y] = false;
}

int main()
{
    cin >> h >> w >> k;
    s.resize(h);
    seen.assign(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) cin >> s[i];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            seen.assign(h, vector<bool>(w, false));
            dfs(i, j, 0);
        }
    }
    cout << ans << endl;

    return 0;
}
