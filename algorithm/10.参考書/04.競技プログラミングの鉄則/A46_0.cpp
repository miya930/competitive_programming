#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> x, y, ans;
vector<bool> visited;
int n;
const double inf = 100100.0;

double GetDistance(int p, int q) {
    return sqrt((x[p]-x[q])*(x[p]-x[q])+(y[p]-y[q])*(y[p]-y[q]));
}

void PlayGreedy(void) {
    int cur = 0;
    ans[0] = cur;
    visited[0] = true;

    for (int i = 1; i < n; ++i) {
        double mi = inf;
        int idx = -1;

        for (int j = 0; j < n; j++) {
            if (visited[j]) continue;
            double dist = GetDistance(cur, j);

            if (mi > dist) {
                mi = dist;
                idx = j;
            }
        }

        visited[idx] = true;
        ans[i] = idx;
        cur = idx;
    }

    ans[n] = 0;
}

int main()
{
    
    cin >> n;
    x.resize(n); y.resize(n);
    visited.assign(n, false);
    ans.assign(n+1, 0);

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    PlayGreedy();

    for (int i = 0; i <= n; ++i) cout << ans[i]+1 << " ";
    cout << endl;

    return 0;
}
