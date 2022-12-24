#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> mp;

ll func(ll n) {
    if (n == 0) return 1;

    if (mp[n] != 0) return mp[n];

    mp[n/2] = func(n/2);
    mp[n/3] = func(n/3);

    return mp[n/2] + mp[n/3];

}

int main()
{
    ll n;
    cin >> n;
    
    cout << func(n) << endl;
    return 0;
}
