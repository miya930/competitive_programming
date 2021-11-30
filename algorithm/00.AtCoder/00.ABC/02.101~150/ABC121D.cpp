#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll cnta = a%4, cntb = b%4;
    ll tempa  = 4 - cnta;
    
    ll ans = 0;
    for (ll i = a; i < a+tempa; ++i) ans ^= i;
        
    
    for (ll i = b; i >= b - cntb; --i) ans ^= i;

    cout << ans << endl;

    return 0;
}
