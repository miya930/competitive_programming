#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int dx[] = {1, 0};
int dy[] = {0, 1};

vector<vector<pair<int,int>>> dp;
vector<string> s;
int h, w;
queue<pair<int,int>> que;

void bfs(int x, int y) {
    que.push(make_pair(x, y));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 2; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            int tmp = dp[vx][vy].first;
            int cur = dp[vx][vy].second;
            if (s[nx][ny] == '#' && s[vx][vy] == '.') tmp++;
            
            if (dp[nx][ny].first == -1 || tmp < dp[nx][ny].first) {
                dp[nx][ny].first = tmp;
                dp[nx][ny].second = cur;               
            } else continue;

            que.push(make_pair(nx, ny));
        }
    }

}

int main()
{
    cin >> h >> w;
    s.resize(h);
    dp.assign(h, vector<pair<int,int>>(w, make_pair(-1, 0)));
    for(int i = 0; i < h; i++) cin >> s[i];

    dp[0][0].first = 0;
    if (s[0][0] == '#') {
        dp[0][0].first++;
        dp[0][0].second = 1;
    }

    bfs(0, 0);

    cout << dp[h-1][w-1].first << endl;

    return 0;
}
