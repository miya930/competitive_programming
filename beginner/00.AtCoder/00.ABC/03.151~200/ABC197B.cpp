#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    // Xからカウントして左右上下の見えるますの数を探す
    int res = 0;
    for (int i = x; i < h; ++i) {
        if (s[i][y-1] == '.') res++;
        else break;
    }
    if (x > 1) {
        for (int i = x-2; i >= 0; --i) {
            if (s[i][y-1] == '.') res++;
            else break;
        }
    }
    for (int i = y; i < w; ++i) {
        if (s[x-1][i] == '.') res++;
        else break;
    }
    if (y > 1) {
        for (int i = y-2; i >= 0; --i) {
            if (s[x-1][i] == '.') res++;
            else break;
        }
    }
    cout << res + 1 << endl;
}
