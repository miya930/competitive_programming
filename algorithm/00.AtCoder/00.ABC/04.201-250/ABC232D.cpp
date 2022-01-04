#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 0};
int dy[] = {0, 1};



int main()
{
    int h ,w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0 ; i < h; ++i) cin >> c[i];

    queue<pair<int,int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));

    int ans = 1;
    dist[0][0] = 1;
    que.push(make_pair(0, 0));

    while (!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 2; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || c[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[vx][vy] + 1;
            que.push(make_pair(nx, ny));
            ans = max(ans,dist[nx][ny]);
        }
    }

    cout << ans << endl;

    return 0;
}
