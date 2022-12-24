#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int r = 0;
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        while(r < n && (a[r]-a[l]) <= k) {
            r++;
        }
        ans += (r-l-1);
        if (r == l) r++;
    }

    cout << ans << endl;

    return 0;
}
