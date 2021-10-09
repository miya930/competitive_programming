#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1), b(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;

    for (int i = 1; i < n; ++i) {
        b[i] = a[i+1] - a[i];
        ans += abs(b[i]);
    }

    for (int i = 0; i < q; ++i) {
        int l, r, v;
        cin >> l >> r >> v;
        long long mae = abs(b[l-1]) + abs(b[r]);
        if (l >= 2) b[l-1] += v;
        if (r <= n-1) b[r] -= v;
        long long ato = abs(b[l-1]) + abs(b[r]);
        ans += (ato - mae);
        cout << ans << endl;
    }
    return 0;
}
