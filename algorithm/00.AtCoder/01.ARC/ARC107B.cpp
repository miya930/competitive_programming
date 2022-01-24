#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (ll i = 2; i <= 2*n; ++i) {
        if (i-k<2 || i-k>2*n) continue;
        ans += ((ll)min(i-1, 2*n+1-i)*min(i-k-1, 2*n+1-i+k));
    }

    cout << ans << endl;
    return 0;
}
