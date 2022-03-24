#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(void)
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = INF;
    for (int i = 0; i <= 9999; ++i) {
        for (int j = 0; j <= 9999; ++j) {
            if ((n-a*i-b*j)%c==0 && (n-a*i-b*j)>=0)
                ans = min(ans, i+j+(n-a*i-b*j)/c);
        }
    }
    cout << ans << endl;
}

/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = infl;
    for (int i = 0; i <= 9999; ++i) {
        for (int j = 0; j <= 9999-i; ++j) {
            ll tmp = n - i*a - j*b;
            ll cnt = i + j;
            if (tmp%c != 0 || tmp < 0) continue;
            cnt += tmp/c;
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}
