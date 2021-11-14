#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int h, w;
char s[60][60];
vector<vector<int> > dist(60, vector<int>(60, -1));
queue<pair<int, int> > que;
// ゴールまで最短距離で行ってその際に使わなかったマスをすべて黒に塗る

void bfs(int sx, int sy) {
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i], ny = vy + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny]=='#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[vx][vy] + 1;
            que.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
        }
    }

    bfs(0, 0);

    int wht = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j]=='.') wht++;
        }
    }

    if (dist[h-1][w-1] != -1) cout << wht - (dist[h-1][w-1]+1) << endl;
    else cout << -1 << endl;
}
