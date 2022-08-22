#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ll P, Q, R;
    cin >> n >> P >> Q >> R;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    bool ok = false;
    for (int i = 0; i <= n; ++i) {
        ll y = sum[i] + P;
        int itr = lower_bound(sum.begin(), sum.end(), y) - sum.begin();
        
        if (itr == n+1) continue;
        else if (sum[itr] == y) {
            ll z = sum[itr] + Q;
            int itr2 = lower_bound(sum.begin(), sum.end(), z) - sum.begin();

            if (itr2 == n+1) continue;
            else if (sum[itr2] == z) {
                ll w = sum[itr2] + R;
                int itr3 = lower_bound(sum.begin(), sum.end(), w) - sum.begin();

                if (itr3 == n+1) continue;
                else if (sum[itr3] == w) {
                    ok = true;
                    break;
                }
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
