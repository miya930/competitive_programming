#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> str(h);
    for (int i = 0; i < h; ++i) cin >> str[i];

    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            if (str[x][y] !=  '.') continue;
            vector<bool> seen(5, false);
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || str[nx][ny] == '.') continue;
                int now = str[nx][ny] - '1';
                seen[now] = true;
            }
            for (int i = 0; i < 5; ++i) {
                if (!seen[i]) {
                    str[x][y] = i + '1';
                    break;
                }
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << str[i][j];
        }
        cout << endl;
    }

    return 0;
}
