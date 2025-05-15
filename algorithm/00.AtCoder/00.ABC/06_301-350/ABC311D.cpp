#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    queue<pair<int,int>> que;
    vector<vector<bool>> dist(n, vector<bool>(m, false));
    int x = 1, y = 1;
    dist[x][y] = true;
    que.push(make_pair(x, y));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx, ny;
            vector<pair<int,int>> path;

            nx = vx;
            ny = vy;

            while(1) {
                nx = nx + dx[i];
                ny = ny + dy[i];

                if (s[nx][ny] == '#') {
                    if (!dist[nx-dx[i]][ny-dy[i]]) {
                        que.push(make_pair(nx-dx[i], ny-dy[i]));
                    }
                    break;
                }

                path.push_back(make_pair(nx, ny));
            }

            for (int j = 0; j < path.size(); j++) {
                int x = path[j].first;
                int y = path[j].second;
                dist[x][y] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
