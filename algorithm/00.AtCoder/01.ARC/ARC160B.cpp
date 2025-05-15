#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n;
        cin >> n;
        int m= sqrt(n);
        ll ans = 0;

        for (int i = 1; i <= m; i++) {
            int x = n / i;
            ans = (ans + 6LL*(i-1)*(x-i)%mod + 3LL*(x-1LL) + 1);
            ans %= mod;
        }
        
        cout << ans << endl;
    }

    return 0;
}
