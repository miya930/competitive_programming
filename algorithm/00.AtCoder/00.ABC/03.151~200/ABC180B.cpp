#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    ll ma = 0, c = -1, tmp = 0;
    double u = 0;
    for (int i = 0; i < n; i++) {
        ma += abs(x[i]);
        c  = max(c, abs(x[i]));
    }
    for (int i = 0; i < n; i++) {
        tmp += (x[i]*x[i]);
    }
    u = sqrt(tmp);

    cout << ma << endl;
    printf("%.15f\n", u);
    cout << c << endl;

    return 0;
}
