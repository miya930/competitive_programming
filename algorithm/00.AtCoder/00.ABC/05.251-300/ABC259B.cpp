#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265358979323846;

int main()
{
    double a, b, d;
    cin >> a >> b >> d;

    double x = cosl(d*pi/(double)180)*a - sinl(d*pi/(double)180)*b; 
    double y = sinl(d*pi/(double)180)*a + cosl(d*pi/(double)180)*b;

    printf("%.20lf %.20lf\n", x,  y);

    return 0;
}
