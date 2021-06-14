#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m+1);
    a[0] = 0;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> b(m+1);

    for (int i = 1; i <= m; ++i) b[i] = a[i] - a[i-1] - 1;
    
    if (a[a.size()-1] != n) b.push_back(n - a[a.size()-1]);
    sort(b.begin(), b.end());

    ll k = INF;
    for (int i = 0; i < (ll)b.size(); ++i) {
        if (b[i] != 0) {
            k = b[i];
            break;
        }
    }

    long long ans = 0;
    if (k == INF) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < b.size(); ++i) ans += (b[i]+k-1)/k;
    cout << ans << endl;
}
