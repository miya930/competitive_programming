#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    ll a, b;
    string s;
    cin >> n >> a >> b >> s;

    ll ans = infl;
    ll asum = 0;
    string str = s;
    for (int i = 0; i < n; i++) {
        ll tmp = asum;

        for (int j = 0; j < n/2; j++) {
            if (str[j] != str[n-j-1]) tmp += b;
        }

        ans = min(ans, tmp);

        char c = str[0];
        for (int j = 0; j < n-1; j++) {
            str[j] = str[j+1];
        }
        str[n-1] = c;
        asum += a;
    }

    cout << ans << endl;
    return 0;
}
