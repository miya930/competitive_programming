#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> f(n, vector<ll>(10)), p(n, vector<ll>(11));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) cin >> f[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) cin >> p[i][j];
    }

    int maidx = 10;
    ll ans = -infl;
    for (int bits = 1; bits < (1<<maidx); ++bits) {
        vector<int> cnt(n, 0);
        ll tmp = 0;
        for (int i = 0; i < maidx; ++i) {
            if ((bits>>i) & 1) {
                for (int j = 0; j < n; ++j) {
                    if (f[j][i]) cnt[j]++;
                }
            }
        }

        for (int i = 0; i < n; ++i) tmp += p[i][cnt[i]];
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
