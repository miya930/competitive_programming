#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m;
queue<pair<int, int> > que;
vector<vector<int> > dist;
char field[1100][1100];

void bfs(int sx, int sy) {
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while (!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i], ny = vy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || field[nx][ny]=='1') continue;
            if (dist[nx][ny] != -1) continue;
            
            que.push(make_pair(nx, ny));
            dist[nx][ny] = dist[vx][vy] + 1; 
        }
    }
}

int main()
{
    cin >> m >> n;
    dist.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char space;
            cin >> field[i][j];
        }
    }
    
    int sx, sy, gx, gy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 's') {
                sx = i;
                sy = j;
            } else if (field[i][j] == 'g') {
                gx = i;
                gy = j;
            }
        }
    }    

    bfs(sx, sy);

    if (dist[gx][gy] == -1) cout << "Fail" << endl;
    else cout << dist[gx][gy] << endl; 

}

