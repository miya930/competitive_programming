#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    ll n;
    cin >> n;
    ll x = n % mod;
    if (x < 0) x = mod + x;

    cout << x << endl;

    return 0;
}
