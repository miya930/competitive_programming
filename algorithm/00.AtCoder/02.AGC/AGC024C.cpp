#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] - last > 1) {
            cout << -1 << endl;
            return 0;
        }
        
        if (a[i] <= last) {
            ans += a[i];
        } else if (a[i] > 0){
            ans++;
        }
        last = a[i];
    }

    cout << ans << endl;
    return 0;
}
