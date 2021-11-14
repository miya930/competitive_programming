// C：最古の遺跡
// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

vector<vector<bool> > exist(5010, vector<bool>(5010, false));

int main()
{
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        exist[x[i]][y[i]] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int dx = abs(x[i]-x[j]);
            int dy = abs(y[i]-y[j]);
            int de = dx*dx + dy*dy;

            int x1[2] = {x[i]-dy, x[i]+dy};
            int x2[2] = {x[j]-dy, x[j]+dy};
            int y1[2] = {y[i]-dx, y[i]+dx};
            int y2[2] = {y[j]-dx, y[j]+dx};

            for (int l = 0; l < 2; ++l) {
                for (int k = 0; k < 2; ++k) {
                    if (x1[l] < 0 || x1[l] > 5000 || y1[k] < 0 || y1[k] > 5000) continue;
                    if (x2[l] < 0 || x2[l] > 5000 || y2[k] < 0 || y2[k] > 5000) continue;
                    if (exist[x1[l]][y1[k]] && exist[x2[l]][y2[k]]) ans = max(ans, de);
                }
            }
        }
    }
    cout << ans << endl;
}
