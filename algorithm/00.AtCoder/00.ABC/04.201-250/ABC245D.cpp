#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), c(n+m+1);
    for (int i = 0; i < n+1 ;++i) cin >> a[i];
    for (int i = 0; i < n+m+1; ++i) cin >> c[i];

    vector<int> b(m+1);

    int cnt = n;
    for (int i = m; i >= 0; --i) {
        b[i] = c[i+n] / a[n];

        if (cnt != 0) cnt--;
        for (int j = cnt; j <= n-1; ++j) {
            if (i+n-j-1 < 0) continue;
            c[i+n-1] -= (a[j]*b[i+n-j-1]);
        }
    }

    for (int i = 0; i <= m; ++i) cout << b[i] << " ";
    cout << endl;

    return 0;
}
