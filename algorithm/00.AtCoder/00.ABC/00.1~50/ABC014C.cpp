#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1000100;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<ll> d(MAX, 0);
    for (int i = 0; i < n; ++i) {
        d[a[i]]++;
        d[b[i]+1]--;
    }
    for (int i = 1; i < MAX; ++i) d[i] += d[i-1];

    ll ans = 0;
    for (int i = 0; i < MAX; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
}
