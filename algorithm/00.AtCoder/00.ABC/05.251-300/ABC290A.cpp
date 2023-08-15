#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }

    int ans = 0;
    for (int i = 0; i < m; i++){
        ans += a[b[i]];
    }

    cout << ans << endl;

    return 0;
}
