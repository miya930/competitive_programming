#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    int dx, dy;
    int px1, px2, py1, py2;
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == 'o') {
                if (cnt == 0) {
                    px1 = i;
                    py1 = j;
                    cnt++;
                } else {
                    px2 = i;
                    py2 = j;
                }
            }
        }
    }

    dx = abs(px1-px2);
    dy = abs(py1-py2);
    
    cout << dx + dy << endl;

    return 0;
}
