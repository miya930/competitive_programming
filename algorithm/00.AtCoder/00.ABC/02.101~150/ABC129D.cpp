#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    vector<vector<int> > l(h, vector<int>(w)), r(h, vector<int>(w)), d(h, vector<int>(w)), u(h, vector<int>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') l[i][j] = 0;
            else {
                if (j == 0) l[i][j] = 1;
                else l[i][j] = l[i][j-1] + 1;
            }
        }
        for (int j = w-1; j >= 0; --j) {
            if (a[i][j] == '#') r[i][j] = 0;
            else {
                if (j == w-1) r[i][j] = 1;
                else r[i][j] = r[i][j+1] + 1;
            }
        }
    }

    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            if (a[i][j] == '#') d[i][j] = 0;
            else {
                if (i == 0) d[i][j] = 1;
                else d[i][j] = d[i-1][j] + 1;
            }
        }
        for (int i = h-1; i >= 0; --i) {
            if (a[i][j] == '#') u[i][j] = 0;
            else {
                if (i == h-1) u[i][j] = 1;
                else u[i][j] = u[i+1][j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = max(ans, r[i][j]+l[i][j]+d[i][j]+u[i][j]-3);
        }
    }
    cout << ans << endl;
}
