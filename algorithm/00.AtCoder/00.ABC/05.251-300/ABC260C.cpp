#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> b(n+1, 0), r(n+1, 0);
    r[1] = 0; b[1] = 1;

    for (int i = 2; i <= n; ++i) {
        b[i] = r[i-1] + b[i-1]*y;
        r[i] = r[i-1] + b[i]*x;
    }

    cout << r[n] << endl;

    return 0;
}
