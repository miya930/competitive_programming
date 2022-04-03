#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.1415926535;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    double c;
    int vol = a*a*b;

    double ans;
    if (vol < 2*x) {
        c = (double)2.0*(a*a*b-x)/(a*a);
        ans = atan((double)a/c)*180.0/pi;
    } else {
        c = (double)2.0*x/(b*a);
        ans = atan((double)c/b)*180.0/pi;
    }
    
    printf("%.10f\n", 90-ans);
    return 0;
}
