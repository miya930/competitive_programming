#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int div = (n+1)/2;
    double ans = (double)div / (double)n;

    printf("%.10f\n", ans);

    return 0;
}
