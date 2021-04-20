#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll between(ll a, ll x) {
    if (a == -1)
        return 0;
    else
        return (a/x + 1);
}

int main(void)
{
    ll a, b, x;
    cin >> a >> b >> x;

    cout << (between(b, x) - between(a-1, x)) << endl;
}
