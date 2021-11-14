#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    if (k == 0) {
        ans = n*n;
        cout << ans << endl;
        return 0;
    }

    for (ll b = k+1; b <= n; ++b) {
        int temp = (n+1)/b;

        ans += temp*(b-k);

        if (k+b*temp <= n) ans += (n-(k+b*temp)+1);
    }

    cout << ans << endl;

    return 0;
}
