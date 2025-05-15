#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), c(n);
    vector<vector<int>> f(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        f[i].resize(c[i]);
        for (int j = 0; j < c[i]; j++) {
            cin >> f[i][j];
        }
    }

    bool ok = false;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i == j) continue;

            if (p[i] >= p[j] && 
               includes(f[j].begin(), f[j].end(), f[i].begin(), f[i].end()) &&
               (p[i] > p[j] || !includes(f[i].begin(), f[i].end(), f[j].begin(), f[j].end()))) {
                ok = true;
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
