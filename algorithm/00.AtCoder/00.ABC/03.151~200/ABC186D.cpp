#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    vector<ll> sum(n+2, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i+1] = sum[i] + a[i-1];
    }

    for (int i = 1; i <= n-1; ++i) {
        ans = ans + (n-i)*a[i-1];
        ans = ans - (sum[n+1] - sum[i+1]);
    }

    cout << ans << endl;
    return 0;
}
