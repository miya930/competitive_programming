#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> seen(n, false);
    seen[x] = true;
    int now = x, ans = 1;

    while (1) {
        now = a[now];
        if (seen[now]) break;
        seen[now] = true;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
