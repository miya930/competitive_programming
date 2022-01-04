#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double inf = 100000000;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    double ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            ans = min(ans, sqrt(dx*dx+dy*dy));
        }
    }

    printf("%.12f\n", ans);
    return 0;
}
