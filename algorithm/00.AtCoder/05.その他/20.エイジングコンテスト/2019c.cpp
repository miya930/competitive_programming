#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<vector<bool>> seen;
vector<string> s;
ll h, w;

pair<ll,ll> dfs(int x, int y) {
    seen[x][y] = true;
    ll a = 1, b = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || seen[nx][ny]) continue;
        if (s[x][y] == s[nx][ny]) continue;

        auto p = dfs(nx, ny);
        a += p.second;
        b += p.first;
    }

    return {a, b};
}

int main()
{
    cin >> h >> w;
    s.resize(h);
    seen.assign(h, vector<bool>(w));
    for (int i = 0; i < h; ++i) cin >> s[i];

    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (seen[i][j]) continue;
            auto p = dfs(i, j);
            ans += p.first*p.second;
        }
    }

    cout << ans << endl;
    return 0;
}
