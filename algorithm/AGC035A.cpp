#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<string> s;
int h, w;

vector<vector<bool>> seen;
bool flag = true;

void dfs(int x, int y) {
    seen[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '.') continue;
        if (seen[nx][ny]) continue;

        if (i == 2 || i == 3) flag = false;

        dfs(nx, ny); 
    }
    
}

int main()
{
    cin >> h >> w;

    s.resize(h);
    seen.assign(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) cin >> s[i];

    dfs(0, 0);
    if (!seen[h-1][w-1] || s[0][0] == '.') flag = false;

    if (flag) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}
