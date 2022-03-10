#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    
    if (x <= a) printf("%.10f\n", 1.0);
    else if (x > a && x <= b) printf("%.12f\n", (double)c/(double)(b-a));
    else printf("%.12f\n", 0.0);

    return 0;
}
