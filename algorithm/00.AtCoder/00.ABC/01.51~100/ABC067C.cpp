/**
   created: 21.10.2021 23:19:38
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    ll ans = infl;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, abs(sum[i] - (sum[n]-sum[i])));
    }

    cout << ans << endl;

    return 0;
}
