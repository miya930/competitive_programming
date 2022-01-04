#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    for (int i = 0; i < r; ++i) cin >> s[i];

    queue<pair<int,int>> que;
    vector<vector<int>> dist(r, vector<int>(c, -1));
    que.push(make_pair(sx, sy));
    dist[sx][sy] = 0;

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || dist[nx][ny] != -1 || s[nx][ny] == '#') continue;

            dist[nx][ny] = dist[vx][vy] + 1;
            que.push(make_pair(nx, ny));
        }
    }

    cout << dist[gx][gy] << endl;
    return 0;
}
