#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];            
        }
    }
    int m;
    cin >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;

    int res = INF;
    do {
        int sum = 0;
        bool bad = false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i < n-1) {
                    if ((x[j] == v[i]+1) && (y[j] == v[i+1]+1))
                        bad = true;
                    if ((y[j] == v[i]+1) && (x[j] == v[i+1]+1))
                        bad = true;
                }
            }
            sum += a[v[i]][i];
        }
        if (sum != 0 && bad == false)
            res = min (res, sum);
    }while (next_permutation(v.begin(), v.end()));

    if (res == INF)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}


/* 2022.3.20 復習 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    int m;
    cin >> m;
    for (int i = 0;i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        b[x][y] = 1;
        b[y][x] = 1;
    }

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) vec[i] = i;

    int ans = inf;
    do {

        bool flag = true;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                int x = vec[i-1];
                int y = vec[i];
                if (b[x][y]) flag = false;
            }
            sum += a[vec[i]][i];
        }

        if (flag) ans = min(ans, sum);

    } while(next_permutation(vec.begin(), vec.end()));

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
