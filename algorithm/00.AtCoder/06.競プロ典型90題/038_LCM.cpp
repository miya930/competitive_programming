#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcm(ll n, ll m) {
    if (m == 0) return n;
    return gcm(m, n % m);
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll r = a / gcm(a, b);
    if (1000000000000000000LL/r >= b)
        cout << r*b << endl;
    else
        cout << "Large" << endl;
}
