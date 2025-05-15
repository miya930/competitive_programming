#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int i = 0; i < 8; i++) {
                int ny = y + 4*dy[i];
                int nx = x + 4*dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

                if (s[y][x] == 's' &&
                    s[y+dy[i]*1][x+dx[i]*1] == 'n' &&
                    s[y+dy[i]*2][x+dx[i]*2] == 'u' &&
                    s[y+dy[i]*3][x+dx[i]*3] == 'k' &&
                    s[y+dy[i]*4][x+dx[i]*4] == 'e') {
                        y++; x++;
                        cout << y  << " " << x << endl;
                        cout << y+dy[i]*1 << " " << x+dx[i]*1 << endl;
                        cout << y+dy[i]*2 << " " << x+dx[i]*2 << endl;
                        cout << y+dy[i]*3 << " " << x+dx[i]*3 << endl;
                        cout << y+dy[i]*4 << " " << x+dx[i]*4 << endl;

                        return 0;
                }
            }
        }
    }

    return 0;
}
