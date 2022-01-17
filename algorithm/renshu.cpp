#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int dx[] = {0, 1};
int dy[] = {1, 0};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    vector<vector<pair<int,int>>> vec(h, vector<pair<int,int>>(w, {inf, 0}));

    vec[0][0].first = 0;
    if (s[0][0] == '#') vec[0][0].first++;
    queue<pair<int,int>> que;
    que.push(make_pair(0, 0));

    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();

        for (int i = 0; i < 2; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];

            int tmp = vec[vx][vy].first;
            if (nx >= h || ny >= w) continue;
            if (s[nx][ny] == '#' && s[vx][vy] == '.') tmp++;

            if (vec[nx][ny].first == inf || tmp < vec[nx][ny].first) {
                vec[nx][ny].first = tmp;
            } else continue;

            que.push(make_pair(nx, ny));
        }
    }

    cout << vec[h-1][w-1].first << endl;
    return 0;
}
