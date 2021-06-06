#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const long double pi = 3.14159265359;

int main()
{
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    pair<double, double> A, B;

    double theta_a = pi / 2 - 2 * pi * (h * 60 + m) / 720;
    double theta_b = pi / 2 - 2 * pi * m / 60;
    A.first = a * cos(theta_a);
    A.second = a * sin(theta_a);
    B.first = b * cos(theta_b);
    B.second = b * sin(theta_b);
    double r_x = A.first - B.first;
    double r_y = A.second - B.second;

    printf("%.15f\n", (double)sqrt(r_x * r_x + r_y * r_y));
    return 0;
}
