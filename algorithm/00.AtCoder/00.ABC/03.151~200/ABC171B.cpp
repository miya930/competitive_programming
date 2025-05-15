#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < k; i++) ans += p[i];

    cout << ans << endl;

    return 0;
}
