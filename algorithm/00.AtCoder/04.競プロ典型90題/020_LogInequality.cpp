#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll tmp = c;
    for (int i = 1; i < b; i++) {
        (c *= tmp) %= MOD;    
    }
    if (c <= (a%MOD))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
