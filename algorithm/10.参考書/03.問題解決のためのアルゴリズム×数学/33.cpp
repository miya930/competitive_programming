#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by  >> cx >> cy;

    ll BAx = ax - bx, BAy = ay - by;
    ll BCx = cx - bx, BCy = cy - by;
    ll CAx = ax - cx, CAy = ay - cy;
    ll CBx = bx - cx, CBy = by - cy;

    int pattern = 2;
    if (BAx*BCx+BAy*BCy < 0LL) pattern = 1;
    if (CAx*CBx+CAy*CBy < 0LL) pattern = 3;

    double ans = 0;
    if (pattern == 1) ans = sqrt(BAx*BAx+BAy*BAy);
    else if (pattern == 3) ans = sqrt(CAx*CAx+CAy*CAy);
    else {
        double area = abs(BAx*BCy-BAy*BCx);
        double len = sqrt(BCx*BCx+BCy*BCy);
        ans = area / len;
    }

    printf("%.12f\n", ans);
    return 0;
}
