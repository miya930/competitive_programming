#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;
    
    ll ans = 1;
    for (int i = 0; i < b; ++i) {
        ans *= a;
    }

    cout << ans << endl;

    return 0;
}
