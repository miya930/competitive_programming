#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    int s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int r = 0;
    ll sum = 0;
    int ans = inf;
    for (int l = 0; l < n; l++) {
        while(r < n || sum < s) {
            sum += a[r];
            r++;
        }
        ans = min(ans, r - l);
        if (r <= l) r++;
        sum -= a[l];
    }

    if (ans == inf) cout << 0 << endl;
    else cout << ans << endl;

    return 0;
}
