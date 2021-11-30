#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    cin >> n;

    double ans = 0;
    for (int i = n-1; i >= 1; --i) ans += (n/(n-i));

    printf("%.8f", ans);
    return 0;
}
