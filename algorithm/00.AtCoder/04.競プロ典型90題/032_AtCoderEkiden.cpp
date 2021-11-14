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
