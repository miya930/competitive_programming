#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    bool isprime = true;
    for (ll i = 2; i * i <= n; ++i) {
        if (n%i == 0) isprime = false; 
    }

    if (isprime) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
