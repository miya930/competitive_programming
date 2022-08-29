#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    int abx = bx - ax;
    int aby = by - ay;
    int adx = dx - ax;
    int ady = dy - ay;
    int cbx = bx - cx;
    int cby = by - cy;
    int cdx = dx - cx;
    int cdy = dy - cy;

    bool yes = true;

    int dab = abx*ady - aby*adx;
    int abc = (-cbx*(-aby)-(-cby)*(-abx));
    int bcd = cdx*cby - cdy*cbx;
    int adc = (-adx*(-cdy)-(-ady)*(-cdx));

    if (dab < 0 || abc < 0 || bcd < 0 || adc < 0) yes = false;

    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
