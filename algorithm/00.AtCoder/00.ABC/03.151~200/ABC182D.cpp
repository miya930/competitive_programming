#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<ll> > m(n+1, vector<ll>(2, 0));
    m[0][0] = 0; m[0][1] = 0;

    for (int i = 0; i < n; ++i) {
        m[i+1][0] = m[i][0] + a[i];
        m[i+1][1] = max(m[i][1], m[i+1][0]);
    }

    vector<ll> sum(n+2, 0);
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        sum[i+1] = sum[i] + m[i][0];
        ans = max(ans, sum[i] + m[i][1]);
        ans = max(ans, sum[i+1]);
    }
    cout << ans << endl;
}
