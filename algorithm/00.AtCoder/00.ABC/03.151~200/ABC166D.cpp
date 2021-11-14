/**
   created: 20.10.2021 23:39:43
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll x;
    cin >> x;

    for (ll a = -1000; a <= 1000; a++) {
        for (ll b = -1000; b <= 1000; b++) {
            ll temp1 = 1, temp2 = 1;
            for (int i = 0; i < 5; ++i) temp1 *= a;
            for (int i = 0; i < 5; ++i) temp2 *= b;
            if (temp1-temp2 == x) {
                cout << a << " " << b << endl;
                return 0;
            } 
        }
    }

    return 0;
}
