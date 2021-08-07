#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    if (a+b <= k) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    if (a >= k) {
        cout << a-k << " " << b << endl;
    } else if (a < k) {
        cout << 0 << " " << b - (k - a) << endl;
    }

    return 0;
}
