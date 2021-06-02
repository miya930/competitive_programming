#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h), d(h);
    for (int i = 0; i < h; ++i) cin >> c[i];

    int ans = 0;
    for (int bits_h = 0; bits_h < (1<<h); ++bits_h) {
        for (int bits_w = 0; bits_w < (1<<w); ++bits_w) {
            int cnt = 0;
            for (int i = 0; i < h; ++i) d[i] = c[i];
            for (int i = 0; i < h; ++i) {
                if (bits_h & (1<<i)) {
                    for (int k = 0; k < w; ++k) d[i][k] = 'R';
                }
            }
            for (int j = 0; j < w; ++j) {
                if (bits_w & (1<<j)) {
                    for (int k = 0; k < h; ++k) d[k][j] = 'R';
                }
            }
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (d[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
