#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            sum += a[i];
        } else {
            ans += sum/2;
            sum = 0;
        }
    }
    if (sum > 0) ans += sum/2;

    cout << ans << endl;
    return 0;
}
