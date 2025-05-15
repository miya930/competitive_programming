#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    vector<pair<ll,ll>> pa(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) {
        pa[i].first = a[i];
        pa[i].second = b[i];
    }
    sort(pa.begin(), pa.end());

    vector<ll> vec(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        vec[i] = pa[i].second;
        sum += pa[i].second;
    }
    if (sum <= m) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        sum -= pa[i].second;
        if (sum <= m) {
            cout << pa[i].first + 1 << endl;
            return 0;
        }
    }

    return 0;
}
