#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = n; i >= 1; --i) {
        ans *= i;
    }

    cout << ans << endl;

    return 0;
}
