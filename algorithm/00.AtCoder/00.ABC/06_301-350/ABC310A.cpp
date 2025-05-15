#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());

    int ans = p;
    ans = min(ans, q + d[0]);
    cout << ans << endl;

    return 0;
}
