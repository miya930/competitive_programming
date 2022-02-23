#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll res = 0;
    res -= a[0];
    res += a[n-1];
    for (int i = 1; i < n-1; ++i) res += abs(a[i]);
    cout << res << endl;

    for (int i = 1; i < n-1; ++i) {
        if (a[i] <= 0) {
            cout << a[n-1] << ' ' << a[i] << endl;
            a[n-1] -= a[i];
        } else {
            cout << a[0] << ' ' << a[i] << endl;
            a[0] -= a[i];
        }
    }
    cout << a[n-1] << ' ' << a[0] << endl;

    return 0;
}
