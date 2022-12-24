#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double inf = 1e40;


int main()
{
    ll a, b;
    cin >> a >> b;

    ll x = pow((double)a/(2*b), (double)2/(double)3) - 1;

    double ans  = inf;
    if (x >= 0) ans = min(ans, (double)b*(double)x + (double)a/sqrt(1+x));
    else ans = min(ans, (double)a/sqrt(1));

    if (x+1 >= 0) ans = min(ans, (double)b*(double)(x+1) + (double)a/sqrt(2+x));
    else ans = min(ans, (double)a/sqrt(1));

    if (x-1 >= 0) ans = min(ans, (double)b*(double)(x-1) + (double)a/sqrt(x));
    else ans = min(ans, (double)a/sqrt(1));

    printf("%.10f\n", ans);
    return 0;
}
