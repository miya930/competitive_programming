#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> x(n, vector<bool>(n)), y(n, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        x[a][b] = x[b][a] = true;
    }

    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        y[c][d] = y[d][c] = true;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    do {
        bool ok = true;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                if (x[i][j] != y[p[i]][p[j]]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
    return 0;

    return 0;
}
