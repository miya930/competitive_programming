#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> t(n), x(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> x[i];

    vector<ll> a, b, c;
    for (int i = 0; i < n; i++) {
        if (t[i] == 0) a.push_back(x[i]);
        else if (t[i] == 1) b.push_back(x[i]);
        else c.push_back(x[i]);
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll> s(n+1, 0), y(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (i < a.size()) s[i+1] = s[i] + a[i];
        else s[i+1] = s[i];
    }

    ll r = 0;
    for (int i = 0; i < n; i++) {
        if (b.empty()) y[i+1] = y[i];
        else if (r == 0) {
            if (!c.empty()) {
                r += c.back();
                c.pop_back();
            }
            y[i+1] = y[i];
        } else {
            r--;
            y[i+1] = y[i] + b.back();
            b.pop_back();
        }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) ans = max(ans, s[i] + y[m-i]);
    cout << ans << endl;
    return 0;
}
