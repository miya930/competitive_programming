#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;
vector<vector<int> > dist(25, vector<int>(25, -1));
queue<pair<int, int> > que;
vector<string> field;
int h, w;

void bfs(int sx, int sy) {
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i], ny = vy + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || field[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            que.push(make_pair(nx, ny));
            dist[nx][ny] = dist[vx][vy] + 1;
            ans = max(ans, dist[nx][ny]);
        }
    }
}

int main()
{
    cin >> h >> w;
    field.resize(h);
    for (int i = 0; i < h; ++i) cin >> field[i];

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (field[i][j] == '#') continue;
            dist.assign(25, vector<int>(25, -1));
            bfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
