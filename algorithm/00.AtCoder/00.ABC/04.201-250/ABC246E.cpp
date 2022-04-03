#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
const int inf = 1001001001;
queue<pair<int,int>> que;
vector<vector<int>> dist(1510, vector<int>(1510, inf));
vector<string> s;
pair<int,int> a, b;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

void bfs(int x, int y) {
    dist[x][y] = 0; 
    que.push({x, y});

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = vx;
            int ny = vy;
            while(1) {
                nx += dx[i];
                ny += dy[i];

                if (nx == b.first && ny == b.second) {
                    dist[b.first][b.second] = dist[vx][vy] + 1;
                    return;
                }

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || s[nx][ny] == '#') break;
                if (dist[nx][ny] != inf) continue;

                dist[nx][ny] = dist[vx][vy]+1;
                que.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> a.first >> a.second >> b.first >> b.second;
    a.first--; a.second--; b.first--; b.second--;

    s.resize(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    if ((a.first+a.second)%2 != (b.first+b.second)%2) {
        cout << -1 << endl;
        return 0;
    }

    bfs(a.first, a.second);

    if (dist[b.first][b.second] == inf) cout << -1 << endl;
    else cout << dist[b.first][b.second] << endl;

    return 0;
}





/****** 4/3復習 ******/

/* 01BFSの使い方を確認.
 * 0：dequeの先頭、1：dequeの末尾にデータを入れていく.
 * 1の場合、距離の更新が発生する.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ppi = pair<pair<int,int>,int>;
const int inf = 1001001001;

int n;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
vector<vector<vector<int>>> d(1510, vector<vector<int>>(1510, vector<int>(4, inf)));
vector<vector<vector<bool>>> seen(1510, vector<vector<bool>>(1510, vector<bool>(4, false)));

int main()
{
    cin >> n;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ax--; ay--; bx--; by--;

    vector<string> s(n);
    deque<ppi> dq;
    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int i = 0; i < 4; ++i) {
        int cx = ax + dx[i];
        int cy = ay + dy[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= n || s[cx][cy] == '#') continue;
        d[cx][cy][i] = 1;
        dq.push_back({{cx, cy}, i});
    }

    while(!dq.empty()) {
        ppi cp = dq.front();
        dq.pop_front();

        int vx = cp.first.first;
        int vy = cp.first.second;
        int cd = cp.second;

        if (vx == bx && vy == by) {
            cout << d[vx][vy][cd] << endl;
            return 0;
        }

        if (seen[vx][vy][cd] == true) continue;     // 訪問済みかどうかはここでチェック
        seen[vx][vy][cd] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || s[nx][ny] == '#') continue;
            
            int ncnt = d[vx][vy][cd];

            if (cd != i) ncnt++;

            if (d[nx][ny][i] > ncnt) {              //　距離の更新があれば更新して deque に入れる。
                d[nx][ny][i] = ncnt;
                if (cd != i) dq.push_back({{nx, ny}, i});
                else dq.push_front({{nx, ny}, i});
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
