#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;
struct pa {
    int a;
    int b;
    ll c;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> d(n, vector<ll>(n, infl));
    vector<pa> p(m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        p[i].a = a; p[i].b = b; p[i].c = c;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a = p[i].a;
        int b = p[i].b;
        ll  c = p[i].c;
        
        int unused = 0;
        for (int j = 0; j < n; ++j) {
            if (d[a][j] + d[j][b] <= c) {
                unused = 1;
            }
        }
        ans += unused;
    }

    cout << ans << endl;
    return 0;
}
