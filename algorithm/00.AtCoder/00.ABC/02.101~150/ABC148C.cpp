#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m)
{
    if (m == 0) return n;
    return gcd(m, n%m);
}

int main(void)
{
    ll A, B;
    cin >> A >> B;
    cout << A / gcd(A, B) * B << endl;
}

