#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, k;
    cin >> x >> k;

    ll now = 10;
    ll bound = 5;
    for (int i = 0; i < k; i++) {
        ll tmp = x % now;
        x -= tmp;
        if (tmp >= bound) {
            x += now;
        }
        bound *= 10;
        now *= 10;
    }

    cout << x << endl;
    return 0;
}
