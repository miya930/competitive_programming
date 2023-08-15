#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1};
int dy[] = {1, 0};

vector<vector<int>> a(100, vector<int>(100));
vector<vector<bool>> seen(100, vector<bool>(100));
int ans = 0;
int h, w;

void dfs(int x, int y, vector<int> &v) {
    if (x == h-1 && y == w-1) {
        ans++;
        return;
    }

    v[a[x][y]] = 1;

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

        int num = a[nx][ny];

        if (v[num] != 0) continue;

        dfs(nx, ny, v);
    }

    v[a[x][y]] = 0;
}

int main()
{
    cin >> h >> w;
    
    vector<int> b;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int c = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
            a[i][j] = c;
        }
    }

    vector<int> vec(200, 0);

    seen[0][0] = true;
    vec[a[0][0]] = 1;
    dfs(0, 0, vec);

    cout << ans << endl;

    return 0;
}
