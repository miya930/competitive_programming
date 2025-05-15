#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    int ma = n;

    int cur = 0;
    for (int i = 0; i < m; i++) {
        n = n - (a[i] - cur);
        if (n <= 0) {
            cout << "No" << endl;
            return 0;
        }
        n = min(ma, n+(b[i] - a[i]));
        cur = b[i];
    }

    n -= (t - cur);
    if (n <= 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
