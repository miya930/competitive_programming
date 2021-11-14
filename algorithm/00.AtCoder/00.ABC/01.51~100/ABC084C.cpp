#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> c(n), s(n), f(n);
    for (int i = 0; i < n-1; ++i) cin >> c[i] >> s[i] >> f[i];

    for (int i = 0; i < n-1; ++i) {
        int ans = 0;
        for (int j = i; j < n-1; ++j) {
            ans = max(ans, s[j]);

            int d = ans - s[j];
            if (d%f[j] != 0) d = f[j] - (d%f[j]);
            else d = 0;

            ans += d + c[j];
        }
        
        cout << ans << endl;
    }
    cout << 0 << endl;
}
