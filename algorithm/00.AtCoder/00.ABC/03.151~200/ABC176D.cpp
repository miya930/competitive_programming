#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<string> s;
vector<vector<int>> dist;
queue<pair<pair<int,int>, int>> que2;
int h, w;

void bfs(int x, int y) {
    que2.push(make_pair(make_pair(x, y), 0));

    while(!que2.empty()) {
        int xx = que2.front().first.first;
        int yy = que2.front().first.second;
        int cnt = que2.front().second;
        que2.pop();

        if (dist[xx][yy] != -1) continue;

        dist[xx][yy] = cnt;

        queue<pair<int,int>> que;
        que.push(make_pair(xx, yy));

        while(!que.empty()) {
            int vx = que.front().first;
            int vy = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = vx + dx[i];
                int ny = vy + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (s[nx][ny] == '#' || dist[nx][ny] != -1) continue;
                
                dist[nx][ny] = cnt;
                que.push(make_pair(nx, ny));
            }

            for (int i = -2; i <= 2; ++i) {
                for (int j = -2; j <= 2; ++j) {
                    if (i == 0 && j == 0) continue;
                    
                    int nx = vx + i;
                    int ny = vy + j;
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (s[nx][ny] == '#' || dist[nx][ny] != -1) continue;

                    que2.push(make_pair(make_pair(nx, ny), cnt+1));
                    
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w;

    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;

    s.resize(h);
    dist.assign(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++i) cin >> s[i];

    bfs(ch, cw);
    cout << dist[dh][dw] << endl;

    return 0;
}
