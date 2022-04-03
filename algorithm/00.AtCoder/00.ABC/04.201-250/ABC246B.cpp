#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    double c = sqrt(a*a+b*b);
    printf("%.10f %.10f", (double)a/c, (double)b/c);

    return 0;
}
