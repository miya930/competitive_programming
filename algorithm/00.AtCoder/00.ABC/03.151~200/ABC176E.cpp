#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> x(m),y(m);
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];

    map<int,int> row, col;
    map<pair<int,int>, bool> mp;
    int rma = 0, cma = 0;
    for (int i = 0; i < m; ++i) {
        row[x[i]]++;
        col[y[i]]++;
        rma = max(rma, row[x[i]]);
        cma = max(cma, col[y[i]]);
        mp[{x[i], y[i]}] = true;
    }

    vector<int> rcan, ccan;
    for (auto v : row) {
        if (v.second == rma) rcan.push_back(v.first);
    }
    for (auto v : col) {
        if (v.second == cma) ccan.push_back(v.first);
    }

    bool flag = false;
    for (auto vx : rcan) {
        for (auto vy : ccan) {
            if (mp[{vx, vy}] == false) {
                flag = true;
                break;
            }
        }
    }

    if (flag) cout << rma + cma << endl;
    else cout << rma + cma -1 << endl;

    return 0;
}
