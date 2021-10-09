/**
   created: 09.10.2021 18:05:32
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<ll> z(n), w(n);

    for (int i = 0 ; i < n; ++i) {
        w[i] = x[i] - y[i];
        z[i] = x[i] + y[i];
    }
    sort(w.begin(), w.end());
    sort(z.begin(), z.end());

    cout << max(w[n-1]-w[0], z[n-1]-z[0]) << endl;
    return 0;
}
