#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    int k;
    cin >> x >> k;

    vector<ll> v(20);
    ll t = 1;
    for (int i = 0; i < 18; i++) {
        v[i] = t;
        t *= 10;
    }

    ll nx = x;
    ll dig = 1;
    for (int i = 0; i < k; i++) {
        nx = x;
        for (int j = 0; j < i; j++) nx /= 10;
        nx %= 10;
        ll tmp = x % v[i+1];
        x -= tmp;
        if (nx >= 5) {
            x += v[i+1];
        }
    }
    cout << x << endl;
    return 0;
}
