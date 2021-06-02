#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;

    ll div = abs(x / d);
    
    if (abs(d * k) < abs(x)) {
        cout << abs(x) - abs(d * k) << endl;
    } else {
        if ((x % d) < 0) int mod = x % d + d;
    }
    
}
