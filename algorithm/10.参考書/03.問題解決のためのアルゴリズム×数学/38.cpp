#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;

        cout << sum[r] - sum[l-1] << endl;
    }

    return 0;
}
