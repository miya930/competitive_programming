#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    int ans = 0;

    if (y > 3*x) {
        cout << x * n << endl;
        return 0;
    }

    while(n > 0) {
        if (n >= 3) {
            ans += y;
            n -= 3;
        } else {
            ans += x*n;
            n = 0;
        }
    }

    cout << ans << endl;
    return 0;
}
