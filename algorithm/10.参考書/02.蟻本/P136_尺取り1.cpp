#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int r = 0, sum = 0, ans = inf;
        int len = 0;
        for (int l = 0; l < n; ++l) {
            while(r < n && sum < s) {
                sum += a[r];
                r++;
            }
            if (sum >= s) ans = min(ans, r-l);
            if (l == r) r++;
            sum -= a[l];
        }

        if (ans == inf) cout << 0 << endl;
        else cout << ans << endl;
    } 


    return 0;
}
