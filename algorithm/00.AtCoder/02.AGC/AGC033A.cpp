#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    queue<pair<int, int>> que;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') que.push(make_pair(i, j));
        }
    }

    int ans = 0;
    while(!que.empty()) {
        ans++;
        queue<pair<int,int>> que2;
        while(!que.empty()) {
            int vx = que.front().first;
            int vy = que.front().second;
            que.pop();

            for (int i= 0; i < 4; ++i) {
                int nx = vx + dx[i];
                int ny = vy + dy[i];
                
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (a[nx][ny] == '.') {
                    a[nx][ny] = '#';
                    que2.push(make_pair(nx, ny));
                }
            }
        }
        que = que2;
    }

    cout << ans-1 << endl;

    return 0;
}
