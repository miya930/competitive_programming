#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const ll INF = 9000000000000000007LL;

ll power (ll num, ll n) {
    ll res = 1;
    for (ll j = 0; j < n; ++j)
        res *= num;
    return res;
}

int main()
{
    ll n;
    cin >> n;

    ll a, b, c;
    ll res = INF;
    for (ll i = 0; i < 64; ++i) {
        c = n % power(2, i);
        a = (n-c) / power(2, i);
        b = i;
        if (a == 0) continue;
        res = min(res, a+b+c);
    }

    cout << res << endl;
}
