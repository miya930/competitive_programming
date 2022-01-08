#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            double tmp = sqrt(dx*dx + dy*dy);
            ans = max(ans, tmp);
        }
    } 

    printf("%.12f\n", ans);
    return 0;
}
