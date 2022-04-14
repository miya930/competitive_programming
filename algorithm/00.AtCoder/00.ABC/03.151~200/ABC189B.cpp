#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n), p(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> p[i];

    int now = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        now += v[i]*p[i];

        if (now > x*100) {
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
