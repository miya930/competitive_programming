#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<ll> a(n),b(n),c(n),d(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i - 0; i < m; ++i) cin >> c[i] >> d[i];

    map<ll, vector<ll>> row, column;

    for (int i = 0; i < m; ++i) row[c[i]].push_back(d[i]);
    for (int i = 0; i < m; ++i) column[d[i]].push_back(d[i]);

    for (auto x : row) {
        sort(x.second.begin(), x.second.end());
    }
    for (auto x : column) {
        sort(x.second.begin(), x.second.end());
    }

    for (int i = 0; i < h; ++i) {

    }

    

    return 0;
}
