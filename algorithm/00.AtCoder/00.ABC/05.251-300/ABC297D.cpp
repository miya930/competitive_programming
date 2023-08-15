#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = 0;

    while(1) {

        if (a == b) {
            break;
        } else if (a < b) {
            ans += (b / a);
            b %= a;
            if (b == 0) {
                b = a;
                ans--;
            }
        } else {
            ans += (a / b);
            a %= b;
            if (a == 0) {
                a = b;
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
