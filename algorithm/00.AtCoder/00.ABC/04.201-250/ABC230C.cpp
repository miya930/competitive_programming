#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    ll lo1 = max(1-a, 1-b);
    ll up1 = min(n-a, n-b);
    ll lo2 = max(1-a, b-n);
    ll up2 = min(n-a, b-1);

    vector<vector<char>> ans(q-p+2, vector<char>(s-r+2));
    for (ll i = 0; i < q-p+1; ++i) {
        for (ll j = 0; j < s-r+1; ++j) {
            ll x1 = p+i-a;
            ll y1 = r+j-b;
            ll x2 = p+i-a;
            ll y2 = r+j-b;
            if (x1 == y1 && lo1 <= x1 && x1 <= up1) ans[i][j] = '#';
            else if (x2 == -y2 && lo2 <= x2 && x2 <= up2) ans[i][j] = '#';
            else ans[i][j] = '.';
        }
    }

    for (ll i = 0; i < q-p+1; ++i) {
        for (ll j = 0; j < s-r+1; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
