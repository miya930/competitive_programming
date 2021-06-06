#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll> > tp(n);

    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        get<1>(tp[i]) = a;
        get<2>(tp[i]) = b;
        get<0>(tp[i]) = 2 * a + b;
    }
    sort(tp.rbegin(), tp.rend());

    ll ans = 0;

    vector<ll> s(n + 1, 0), s_c(n + 1, 0);
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + get<1>(tp[i]);
    for (int i = 0; i < n; ++i) s_c[i + 1] = s_c[i] + get<1>(tp[i]) + get<2>(tp[i]);

    for (int i = 1; i <= n; ++i) {
        ans++;
        ll sum = s_c[i];
        if (sum > s[n] - s[i]) break;
    }
    cout << ans << endl;

}
