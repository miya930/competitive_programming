#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<bool>> dpx(1100, vector<bool>(21000, false)), dpy(1100, vector<bool>(21000, false));

int main()
{
    const int offset = 10000;
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (i%2 == 0) {
            a.push_back(t);
        } else {
            b.push_back(t);
        }
    }
    dpx[0][offset] = true;
    dpy[0][offset] = true;

    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = -10000; j <= 10000; j++) {
            int cur = j + offset;
            if (dpx[i][cur] == false) continue;
            if (cur+a[i] <= 20000) dpx[i+1][cur+a[i]] = true;
            if (cur-a[i] >= 0 && i != 0) dpx[i+1][cur-a[i]] = true;
        }
    }
    for (int i = 0; i < (int)b.size(); i++) {
        for (int j = -10000; j <= 10000; j++) {
            int cur = j + offset;
            if (!dpy[i][cur]) continue;

            if (cur+b[i] <= 20000) dpy[i+1][cur+b[i]] = true;
            if (cur-b[i] >= 0) dpy[i+1][cur-b[i]] = true;           
        }
    }

    int posx = x + offset;
    int posy = y + offset;

    if (dpx[a.size()][posx] && dpy[b.size()][posy]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
