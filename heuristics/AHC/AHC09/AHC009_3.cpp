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

bool checkroot(string str, int &cnt) {
    int si = str.size();
    int x = sx, y = sy;

    bool flag = false;
    for (int i = 0; i < (int)str.size(); ++i) {
        cnt++;
        switch(str[i]) {
            case 'U': 
                if (x > 0 && v[x-1][y] == '0') x--;
                break;
            case 'D':
                if (x < 19 && v[x][y] == '0') x++;
                break;
            case 'L':
                if (y > 0 && h[x][y-1] == '0') y--;
                break;
            case 'R':
                if (y < 19 && h[x][y] == '0') y++;
                break;
        }

        if (x == tx && y == ty) {
            flag = true;
            break;
        }
    }

    return flag;
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
    }

    string ans2 = "";
    curx = sx; cury = sy;
    double ES = 0;
    int bp = 0;
    reverse(ans.begin(), ans.end());

    for (int pp = 1; pp <= 100; ++pp) {
        double es = 0;
        string tmp = "";
        
        for (int cnt = 0; cnt < 1000; cnt++) {
            string str = "";
            
            /* root */
            for (int i = 0; i < (int)ans.size(); ++i) {
                int ran = rand() % 100;
                str += ans[i];
                if (ran <= pp) {
                    str += ans[i];
                }
                if (i != 0 && i%9 == 0) {
                    int ran2 = rand() % 2;
                    if (ran2 == 0) str += 'L';
                    else str += str += 'R';
                    str += 'D';
                }
            }

            /* check */
            int turn = 0;
            if (checkroot(str, turn)) {
                if (str.size() <= 200) {
                    es += (double)(401-turn);
                    tmp = str;
                }
            }
        }

        es /= (double)1000;
        if (ES < es) {
            ES = es;
            bp = pp;
            ans2 = tmp;
        }
    }

    cout << ans2 << endl;
    return 0;
}
