#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

vector<vector<int>> d(210, vector<int>(210, inf));

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> dest(r);
    for (int i = 0; i < r; ++i) {
        cin >> dest[i];
        dest[i]--;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    vector<int> ord(r);
    for (int i = 0; i < r; ++i) ord[i] = i;
    
    int ans = inf;
    do {
        int tmp = 0;
        for (int i = 0; i < r-1; ++i) {
            int from = dest[ord[i]];
            int to   = dest[ord[i+1]];
            tmp += d[from][to];
        }
        ans = min(ans, tmp);
    } while(next_permutation(ord.begin(), ord.end()));

    cout << ans << endl;
    return 0;
}
