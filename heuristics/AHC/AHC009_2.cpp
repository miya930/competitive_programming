#include <bits/stdc++.h>
using namespace std;

const int ver = 19;
const int hor = 20;
const int ma  = 200;
int sx, sy, tx, ty;
double p;
vector<string> h(hor), v(ver);
string ans = "";

void input(void) {
    cin >> sx >> sy >> tx >> ty >> p;
    for (int i = 0; i < hor; ++i) cin >> h[i];
    for (int i = 0; i < ver; ++i) cin >> v[i];
    return;
}

queue<pair<int,int>> que;
vector<vector<pair<int,int>>> rec(20, vector<pair<int,int>>(20, {-1, -1}));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
    que.push(make_pair(x, y));
    rec[x][y].first = 0;
    rec[x][y].second = 0;

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];

            if (nx < 0 || nx >= 20 || ny < 0 || ny >= 20 || (rec[nx][ny].first != -1 && rec[nx][ny].second != -1)) continue;
            if (nx != vx && v[min(vx, nx)][ny] == '1') continue;
            if (ny != vy && h[nx][min(vy, ny)] == '1') continue; 

            rec[nx][ny].first = vx;
            rec[nx][ny].second = vy;
            que.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    input();

    bfs(sx, sy);

    int curx = tx, cury = ty;
    while(curx != sx || cury != sy) {
        int vx = rec[curx][cury].first;
        int vy = rec[curx][cury].second;

        if (vx < curx) ans += 'D';
        if (vx > curx) ans += 'U';
        if (vy < cury) ans += 'R';
        if (vy > cury) ans += 'L';

        curx = vx;
        cury = vy;
        if (ans.size() == 200) break;
    }

    if (ans.size() == 200) {
        cout << ans << endl;
        return 0;
    }

    string ans2 = "";
    for (int i = 0; i < (int)ans.size(); ++i) {
        ans2 += ans[i];
        int ran1 = rand() % 100;
        int pp = (int)(p*100);
        if (ran1 <= 4*pp) {
            ans2 += ans[i];
        }
        
        if (i!= 0 && i%10 == 0) {
            ans2 += 'L';
            ans2 += 'D';
        }
    }

    reverse(ans2.begin(), ans2.end());
    cout << ans2 << endl;
    return 0;
}
