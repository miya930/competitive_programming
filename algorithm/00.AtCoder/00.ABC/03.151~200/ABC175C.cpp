#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1000000000000000000LL;

int main()
{
    long long x, k, d;
    cin >> x >> k >> d;

    if (abs(x/d) > abs(k)) {
        cout << abs(x) - abs(k*d) << endl;
        return 0;
    }

    if (x < 0) x *= -1;

    long long ans = INF;
    long long div = x/d;
    long long mod = x%d;

    if (div%2 == k%2) ans = mod;
    else ans = mod - d;

    if (ans < 0) ans *= -1;

    cout << ans << endl;
    return 0;
}
