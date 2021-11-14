#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int h, w, n;

vector<vector<int> > dist;
queue<pair<int, int> > que;
vector<vector<char> > field;

void bfs(int sx, int sy) {
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i], ny = vy + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || field[nx][ny]=='X') continue;
            if (dist[nx][ny]!=-1) continue;

            dist[nx][ny] = dist[vx][vy] + 1;
            que.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    cin >> h >> w >> n;
    field.assign(h, vector<char>(w));

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> field[i][j];
            if (field[i][j] != '.' && field[i][j] != '#') {
                if (field[i][j]=='S') q.push(make_pair(0, make_pair(i, j)));
                else q.push(make_pair(field[i][j] - '0', make_pair(i, j)));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dist.assign(h, vector<int>(w, -1));
        bfs(q.top().second.first, q.top().second.second);
        q.pop();
        ans += dist[q.top().second.first][q.top().second.second];
    }

    cout << ans << endl;
}
