#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int r, c;

vector<vector<char> > field;
vector<vector<int> > dist;
queue<pair<int, int> > que;

void dfs(int sx, int sy) {
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while (!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0 ; i < 4; ++i) {
            int nx = vx + dx[i], ny = vy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || field[nx][ny]=='#') continue;
            if (dist[nx][ny]!=-1) continue;

            dist[nx][ny] = dist[vx][vy] + 1;
            que.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    cin >> r >> c;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;

    dist.assign(r, vector<int>(c,-1));
    field.assign(r, vector<char>(c));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> field[i][j];
        }
    }
    
    dfs(sx, sy);

    cout << dist[gx][gy] << endl;

}
