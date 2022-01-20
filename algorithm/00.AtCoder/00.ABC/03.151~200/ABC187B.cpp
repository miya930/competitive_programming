#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if (dx == 0) continue;
            if (-1*dy <= dx && dy <= dx) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
