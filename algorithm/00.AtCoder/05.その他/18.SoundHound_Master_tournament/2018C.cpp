#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, d;
    cin >> n >> m >> d;

    ll si = 0;
    si += (max(0LL,2LL*(n-2LL*d))+2LL*d);
    if (d == 0) si = n;
    double ans = (double)si/(n*n)*(m-1);

    printf("%.12f\n", ans);

    return 0;
}
