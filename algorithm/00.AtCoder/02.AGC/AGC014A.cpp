#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (a%2 == 1 || b%2 == 1 || c%2 == 1) {
        cout << 0 << endl;
        return 0;
    } else if (a == b && b == c) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while(1) {
        int aa = a, bb = b, cc = c;
        a = bb/2 + cc/2;
        b = aa/2 + cc/2;
        c = aa/2 + bb/2;
        ans++;
        if (a == b && b == c) {
            cout << -1  << endl;
            return 0;
        }
        if (a%2 == 1 || b%2 == 1 | c%2 == 1) {
            cout << ans << endl;
            return 0;
        }
    }


    return 0;
}
