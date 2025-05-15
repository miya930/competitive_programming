#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n+1, 0), b, c;
    for (int i = 1; i < n; i += 2) {
        sum[i/2+1] = sum[i/2] + (a[i+1] - a[i]);
        b.push_back(a[i+1]);
        c.push_back(a[i]);
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int r, l;
        cin >> l >> r;

        int idx1 = upper_bound(b.begin(), b.end(), l) - b.begin();
        int idx2 = upper_bound(c.begin(), c.end(), r) - c.begin();

        ll s = sum[idx2] - sum[idx1];

        if (l <= b[idx1] && c[idx1] <= l) s -= (l - c[idx1]);
        if (r <= b[idx2-1] && c[idx2-1] <= r) s -= (b[idx2-1] - r);

        cout << s << endl;
    }

    return 0;
}
