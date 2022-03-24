#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;
vector<vector<ll>> dist, dp(1<<18, vector<ll>(20, 0));

int main()
{
    int n;
    cin >> n;
    dist.assign(n, infl);
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]) + max(0LL, z[j]-z[i]);
        }
    }

    return 0;
}
