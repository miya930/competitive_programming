#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> t(n), a(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> a[i];

    vector<int> ans(n, 0);
    for (int bit = 0; bit < 30; bit++) {
        vector<int> v(2, 0);
        v[0] = 0; v[1] = 1;
        int cur = (c >> bit) & 1;
        for (int i = 0; i < n; i++) {
            vector<int> nv(2, 0);
            int op = (a[i] >> bit) & 1;

            if (t[i] == 1) {
                nv[0] = op & 0;
                nv[1] = op & 1;
            } else if (t[i] == 2) {
                nv[0] = op | 0;
                nv[1] = op | 1;
            } else {
                nv[0] = op ^ 0;
                nv[1] = op ^ 1;
            }
            v[0] = nv[v[0]];
            v[1] = nv[v[1]];
            cur = v[cur];
            ans[i] |= (cur << bit);
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}
