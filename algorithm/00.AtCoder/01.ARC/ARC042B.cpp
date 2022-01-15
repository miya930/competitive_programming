#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int X, Y, n;
    cin >> X >> Y >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    x.push_back(x[0]);
    y.push_back(y[0]);

    double ans = 100000000.0;

    for (int i = 0; i < n; ++i) {
        int a = x[i] - X;
        int b = y[i] - Y;
        ans = min(ans, sqrt(a*a+b*b));
    }

    for (int i = 0; i < n; ++i) {
        int OAx = x[i] - X;
        int OAy = y[i] - Y;
        int OBx = x[i+1] - X;
        int OBy = y[i+1] - Y;
        int ABx = x[i] - x[i+1];
        int ABy = y[i] - y[i+1];
        double ABlen = sqrt(ABx*ABx+ABy*ABy);
        double tmp = (double)(OAx*OBy - OAy*OBx)/ABlen;
        ans = min(ans, tmp);
    }

    printf("%.12f\n", ans);
    return 0;
}
