/***
 * ñ¿òHÇÃç≈íZòH
 * 2éüå≥BFS
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int inf = 1000000007;
typedef pair<int, int> p;
vector<string> s;
int n, m;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int siz = 300;
vector<int> dp(siz, vector<int>(siz,inf));

int bfs(int sx, int sy) {
    queue<p> que;
    dp[sx][sy] = 0;
    que.push(p(sx, sy));

    while(!que.empty()) {
        p q = que.front();
        que.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = q.first + dx[i], ny = q.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny]=='#') continue;
            dist[nx][ny] = dist[q.first][q.second] + 1;
            que.push(P(nx, ny));
        }
    }
}

// à»â∫è»ó™
