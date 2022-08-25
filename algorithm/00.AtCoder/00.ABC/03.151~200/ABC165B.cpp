#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    cin >> x;

    ll ans = 0;
    ll cur = 100;
    while(1) {
        cur = cur + cur/100;
        ans++;
        if ((ll)cur >= x) break;
    }

    cout << ans << endl;

    return 0;
}
