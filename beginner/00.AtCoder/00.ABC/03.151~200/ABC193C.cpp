#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    unordered_set<ll> s;
    for (ll i = 2; i*i <= n; ++i) {
        ll x = i*i;
        for (ll j = x; j <= n; j *= i) s.insert(j);
    }

    cout << n - (ll)s.size() << endl;

}
