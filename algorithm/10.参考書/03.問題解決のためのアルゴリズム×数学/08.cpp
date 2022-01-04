#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i+j <= s) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
