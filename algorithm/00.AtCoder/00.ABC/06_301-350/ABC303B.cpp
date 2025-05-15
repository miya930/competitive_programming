#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    vector<vector<bool>> b(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n-1; j++) {
            int u = a[i][j];
            int v = a[i][j+1];
            u--; v--;

            b[u][v] = true;
            b[v][u] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!b[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
