#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    double ans = 1;
    for (int i = n-1; i > 0; --i) ans += 1.0*n/i;

    printf("%.12f\n", ans);
    return 0;
}
