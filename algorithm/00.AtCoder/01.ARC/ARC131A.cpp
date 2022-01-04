#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = a;
    ll tmp = ans;
    int cnt = 0;
    while (tmp > 0) {
        tmp /= 10;
        cnt++;
    }
    for (int i = 0; i < cnt+1; ++i) b *= 10;
    ans += b/2;

    cout << ans << endl;

    return 0;
}
