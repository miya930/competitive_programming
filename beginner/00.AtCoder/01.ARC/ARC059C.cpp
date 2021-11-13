#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ma = 0, mi = inf;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }

    int ans = inf;
    for (int x = mi; x <= ma; ++x) {
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += (x-a[i])*(x-a[i]);
        }
        ans = min(ans, tmp);
    }
    
    cout << ans << endl;
    return 0;
}
