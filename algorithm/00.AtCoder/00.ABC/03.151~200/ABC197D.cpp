#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = 3.1415926535897;

int main()
{
    int n;
    cin >> n;
    
    double xo, yo, xh, yh;
    cin >> xo >> yo >> xh >> yh;

    double theta = 360.0 / n * pi / 180.0;
    double xm = (xo+xh)/2.0, ym = (yo+yh)/2.0;

    double x_ = cos(theta) * (xo-xm) - sin(theta) * (yo-ym);
    double y_ = sin(theta) * (xo-xm) + cos(theta) * (yo-ym);

    printf("%.10f %.10f\n", x_+xm, y_+ym);
    return 0;
}
