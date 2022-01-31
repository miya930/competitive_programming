#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1000000;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));

    int mi = inf;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            mi = min(mi, a[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = ans + a[i][j] - mi;
        }
    }

    cout << ans << endl;

    return 0;
}
