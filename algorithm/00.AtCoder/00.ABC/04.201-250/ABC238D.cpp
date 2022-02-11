#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        ll a, s;
        cin >> a >> s;

        vector<bool> used(61, false);
        for (ll i = 0; i < 61; ++i) {
            if ((a>>i) & 1) used[i] = true;
        }

        s -= 2*a;
        bool ok = true;
        for (ll i = 60; i >= 0; i--) {
            ll tmp = (1LL<<i);
            if (tmp > s) continue;

            s -= tmp;
            if (used[i] == true) ok = false;
        }

        if (s != 0) ok = false;

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}
