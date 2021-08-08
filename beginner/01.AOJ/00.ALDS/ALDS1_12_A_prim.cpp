// prim
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cost[110][110];
const int INF = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<bool> used(n, false);
    vector<int> mincost(n, INF);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            if (a == -1) cost[i][j] = INF;
            else {
                cost[i][j] = a;
            }
        }
    }

    mincost[0] = 0;
    int res = 0;

    while(true) {
        int v = -1;

        for (int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;
        res += mincost[v];

        for (int u = 0; u < n; ++u) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }

    cout << res << endl;
}
