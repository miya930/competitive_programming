#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    int now_b = 0, now_c = 0;;
    for (int i = 0; i < n; ++i) {
        auto iter_b = upper_bound(b.begin() + now_b, b.end(), a[i]);
        if (iter_b == b.end()) continue;
        int ib = iter_b - b.begin();
        now_b = ib + 1;

        auto iter_c = upper_bound(c.begin() + now_c, c.end(), b[ib]);
        if (iter_c == c.end()) continue;
        int ic = iter_c - c.begin();
        now_c = ic + 1;

        ans++;
    }
    cout << ans << endl;
}
