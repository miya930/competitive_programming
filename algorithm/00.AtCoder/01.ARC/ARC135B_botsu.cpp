#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL<<60;

int main()
{
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<ll> a(n+2, 0);
    for (int i = 0; i < n; ++i) {
        a[i+2] = s[i] - a[i+1] - a[i];
    }

    ll c1 = infl, c2 = infl, c3 = infl;
    for (int i = 0; i < n; i+=3) {
        c1 = -1LL*min(c1, a[i]);
        c2 = -1LL*min(c2, a[i+1]);
        c3 =      min(c3, a[i+2]);
    }

    if (c1 + c2 > c3) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n; i+=3) {
        a[i]   += c1;
        a[i+1] += c2;
        a[i+2] -= (c1+c2);
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n+2; ++i) cout << a[i] << " ";

    return 0;
}
