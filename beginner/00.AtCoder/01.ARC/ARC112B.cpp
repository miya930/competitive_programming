#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll b, c;
    cin >> b >> c;

    long long l1 = b - c/2;
    long long r1 = b;

    if (c > 2) {
        r1 = b + (c-2)/2;
    }

    long long l2 = -b - (c-1)/2;
    long long r2 = -b + (c-1)/2;

    if (r1 < l2 || r2 < l1) {
        cout << (r1 - l1 + 1) + (r2 - l2 + 1) << endl;
    } else {
        cout << max(r1, r2) - min(l1, l2) + 1 << endl;
    }
    return 0;
}
