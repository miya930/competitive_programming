#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = 0;
        
        ll t1 = min(b/2, c);
        b -= 2*t1;
        c -= t1;
        ll t2 = min(a, c/2);
        c -= 2*t2;
        a -= t2;
        ll t3 = min(a/2, b/2);
        a -= 2*t3;
        b -= 2*t3;
        ll t4 = min(a/3, c);
        a -= 3*t4;
        c -= t4;
        ll t5 = a/5;

        ans = t1 + t2 + t3 + t4 + t5;
        cout << ans << endl;
    }

    return 0;
}
