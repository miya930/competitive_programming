#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n-1);
    vector<ll> x(m), y(m);
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        x[i]--;
    }

    bool flg = true;
    int num = 0;
    for (int i = 0; i < n-1; ++i) {
        t -= a[i];
        if (t <= 0) {
            flg = false;
            break;
        } else {
            if (num < m && x[num] == i+1) {
                t += y[num];
                num++;
            }
        }
    }
    
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
