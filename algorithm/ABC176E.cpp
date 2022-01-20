#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> row(m), col(m);
    map<int,int> rcnt, ccnt;

    for (int i = 0; i < m; ++i) {
        cin >> row[i] >> col[i];
        row[i]--; col[i]--;
        rcnt[row[i]]++;
        ccnt[col[i]]++;
    }

    int rma = 0, ridx = -1, cma = 0, cidx = -1;
    for (auto x : rcnt) {
        if (rma <= x.second) {
            rma = x.second;
            ridx = x.first;
        }
    }
    for (auto x : ccnt) {
        if (cma <= x.second) {
            cma = x.second;
            cidx = x.first;
        }
    }

    bool flag = true;
    for (int i = 0; i < m; ++i) {
        if (row[i] == ridx && col[i] == cidx) flag = false;
    }

    int ans = rma + cma;
    cout << "rma = " << rma << " " << "  ridx = " << ridx << "   cma = " << cma << "  cidx = " << cidx << endl;
    if (!flag) ans--;

    cout << ans << endl;
    return 0;
}
