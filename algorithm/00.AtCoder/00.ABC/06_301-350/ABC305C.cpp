#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int mix = 1000, miy = 1000, maxx = -1, maxy = -1; 
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                mix = min(mix, i);
                miy = min(miy, j);
                maxx = max(maxx, i);
                maxy = max(maxy, j);
            }
        }
    }

    for (int i = mix; i <= maxx; i++) {
        for (int j = miy; j <= maxy; j++) {
            if (s[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
