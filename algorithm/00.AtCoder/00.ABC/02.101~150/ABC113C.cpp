#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m), y(m);
    for (int i = 0; i < m; ++i) cin >> p[i] >> y[i], --p[i];

    vector<vector<int> > vals(n);
    for (int i = 0; i < m; ++i) vals[p[i]].push_back(y[i]);

    for (int v = 0; v < n; ++v) {
        sort(vals[v].begin(), vals[v].end());

        vals[v].erase(unique(vals[v].begin(), vals[v].end()), vals[v].end());
    }

    for (int i = 0; i < m; ++i) {
        int v = p[i];
        printf("%06d", v + 1);
        int id = lower_bound(vals[v].begin(), vals[v].end(), y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }

}
