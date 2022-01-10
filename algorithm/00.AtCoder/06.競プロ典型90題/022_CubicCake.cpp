#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll GCD(ll n, ll m) {
    if (m == 0) return n;

    return GCD(m, n%m);
}

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll gcd;
    gcd = GCD(a, GCD(b, c));

    cout << a/gcd + b/gcd + c/gcd - 3 << endl;
}
