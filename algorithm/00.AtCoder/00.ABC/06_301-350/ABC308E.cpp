#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;

    vector<vector<ll>> m(3, vector<ll>(n+1, 0)), x(3, vector<ll>(n+1, 0)), e(3, vector<ll>(n+1, 0));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            m[a[i]][i+1]++;
        } else if (s[i] == 'X') {
            x[a[i]][i+1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            m[j][i+1] += m[j][i];
            x[j][i+1] += x[j][i];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if ((j != k) && (j != a[i]) && (k != a[i])) {
                        ans += (m[j][i] * (x[k][n] - x[k][i+1]) * 3LL);
                    } else {
                        bool zero = false, one = false, two = false;
                        if (j == 0 || a[i] == 0 || k == 0) zero = true;
                        if (j == 1 || a[i] == 1 || k == 1) one = true;
                        if (j == 2 || a[i] == 2 || k == 2) two = true;

                        if (!zero)     ans += 0;
                        else if (!one) ans += (m[j][i] * (x[k][n] - x[k][i+1]) * 1LL);
                        else if (!two) ans += (m[j][i] * (x[k][n] - x[k][i+1]) * 2LL);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
