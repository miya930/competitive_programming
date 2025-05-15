#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {-1, 1, -1, 1};
int dy[] = {-1, -1, 1, 1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; i++) cin >> c[i];
    
    vector<int> ans(200, 0);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (c[y][x] != '#') continue;
            bool isng = false;

            int tmp = 0;
            for (int d = 1; d < 100; d++) {
                if (isng) break;

                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i] * d;
                    int nx = x + dx[i] * d;
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w || c[ny][nx] != '#') {
                        isng = true;
                        break;
                    }
                }

                if (!isng) tmp = d;
            }

            if (tmp != 0) ans[tmp]++;
        }
    }

    for (int i = 1; i <= min(h, w); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
