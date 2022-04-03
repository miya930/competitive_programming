#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

ll f(ll a, ll b) {
    return (a*a*a + a*a*b + a*b*b+ b*b*b);
}

int main()
{
    ll n;
    cin >> n;

    ll x = infl;
    ll j = 1000000;
    for (ll i = 0; i < 1000000; ++i) {
        while(f(i, j) >= n && j >= 0) {
            x = min(f(i, j), x);
            j--;
        }
    }

    cout << x << endl;
    return 0;
}
