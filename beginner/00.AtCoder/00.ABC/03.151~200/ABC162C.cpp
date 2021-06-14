#include <iostream>
#include <vector>
using namespace std;

int gcd (int n, int m) {
    if (m == 0) return n;
    return gcd(m, n%m);
}

int main()
{
    int k; cin >> k;

    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1;  l <= k; ++l) {
                int gc = gcd(i, j);
                gc = gcd(gc, l);
                ans += gc;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
