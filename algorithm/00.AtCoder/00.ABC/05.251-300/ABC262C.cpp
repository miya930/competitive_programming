#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    ll cnt = 0;
    ll ans = 0;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) cnt++;
        else {
            int v = a[i];
            if (a[v] == i && seen[i] == false && seen[v] == false) {
                ans++;
                seen[i] = true;
                seen[v] = true;
            }
        }
    }

    ans += cnt * (cnt-1)/2;

    cout << ans << endl;
    return 0;
}
