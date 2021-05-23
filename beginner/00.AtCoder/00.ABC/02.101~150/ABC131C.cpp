#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcb(ll n, ll m) {
    if (m == 0) return n;
    return gcb(m, n%m);
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll sum = 0;
    sum += b/c - (a+c-1)/c;
    sum += b/d - (a+d-1)/d;
    ll lcb = c/gcb(c, d)*d;
    sum -= b/lcb - (a+lcb-1)/lcb;

    cout << b - a - sum << endl;

}
