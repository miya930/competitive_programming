#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int plus = 0, minus = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        if (0 < a[i]) plus++;
        else if (0 > a[i]) minus++;
        else zero++;
    }

    ll ans = 0;
    if (minus%2 == 0) {
        for (int i = 0; i < n; ++i) {
            ans += abs(a[i]);
        }
    } else if (zero > 0) {
        for (int i = 0; i < n; ++i) {
            ans += abs(a[i]);
        }
    } else {
        int mi = inf;
        for (int i = 0; i < n; ++i) mi = min(mi, abs(a[i]));
        for (int i = 0; i < n; ++i) ans += abs(a[i]);
        ans -= 2*mi;
    }
    cout << ans << endl;
}
