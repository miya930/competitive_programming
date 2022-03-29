#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

ll dist[20][20];
ll dp[1<<20][20];
int n;

int func(int s,int v) {
    if (s == 0) {
        if (v == 0) {
            return 0;
        } else {
            return inf;
        }
    }

    if ((s & (1<<v)) == 0) return inf;

    int ret = dp[s][v];
    if (ret != 0) return ret;

    ret = inf;
    for (int i = 0; i < n; ++i) {
        int tmp = func(s ^ (1<<v), i) + dist[i][v];
        if (tmp < ret) ret = tmp;
    }
    
    return dp[s][v] = ret;
}

int main()
{
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n;  ++i) cin >> x[i] >> y[i] >> z[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0, z[j]-z[i]);
        }
    }

    cout << func((1<<n)-1, 0) << endl;

    return 0;
}
