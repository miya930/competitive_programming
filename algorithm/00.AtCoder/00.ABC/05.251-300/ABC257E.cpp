#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int m = 9;
    vector<ll> c(m);
    for (int i = 0; i < m; i++) cin >> c[i];

    ll mi = *min_element(c.begin(), c.end());
    int dig = n / mi;

    string ans = "";
    for (int i = 0; i < dig; i++) {
        for (int j = m-1; j >= 0; j--) {
            if (mi * (ll)(dig - 1 - i) + c[j] <= n) {
                n -= c[j];
                ans.push_back('0'+j+1);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
