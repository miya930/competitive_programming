#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    string t;
    cin >> n >> t;

    if (n == 1) {
         if (t[0] == '1') cout << (ll)1e10 * 2LL << endl;
         else cout << (ll)1e10 << endl;
    } else if (n == 2) {
        if (t == "01") cout << (ll)1e10-1 << endl;
        else if (t == "00") cout << 0 << endl;
        else cout << (ll)1e10 << endl;
    } else {
        bool ex = true;
        for (int i = 0; i < n-2; ++i) {
            if ((t[i]-'0') + (t[i+1] - '0') + (t[i+2] - '0') != 2) ex = false;
        }

        if (!ex) {
            cout << 0 << endl;
            return 0;
        }

        ll z = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == '0') z++;
        }

        if (t[n-1] == '0') cout << (ll)1e10 - z + 1 << endl;
        else cout << (ll)1e10 - z << endl;
    }

    return 0;
}
