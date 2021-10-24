#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int k, t;
    cin >> k >> t;
    vector<int> a(t);

    int tot = 0;
    for (int i = 0; i < t; ++i) {
        cin >> a[i];
        tot += a[i];
    }

    int ans = 0;
    for (int i = 0; i < t; ++i) {
        int space = a[i] - 1;
        if (tot-a[i] < a[i] - 1) ans += (a[i]-1 - (tot-a[i]));
    }

    cout << ans << endl;

    return 0;
}
