#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1000000007;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<ll> > a(n, vector<ll>(m));
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    ll ans = INF;
    for (int bits = 0; bits < (1<<n); ++bits) {
        vector<ll> skill(n, 0);
        ll sum = 0;
        bool achieve = true;
        for (int i = 0; i < n; ++i) {
            if (bits & (1<<i)) {
                sum += c[i];
                for (int j = 0; j < m; ++j) {
                    skill[j] += a[i][j];
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            if (skill[j] < x) achieve = false;
        }
        if (achieve) ans = min(ans, sum);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
