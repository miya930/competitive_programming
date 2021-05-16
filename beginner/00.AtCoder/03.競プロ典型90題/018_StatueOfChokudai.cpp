#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const long double PI = 3.14159265358979;

int main()
{
    int q;
    long double t, l, x, y;
    cin >> t >> l >> x >> y >> q;
    vector<int> e(q);
    for (int i = 0; i < q; ++i) cin >> e[i];

    for (int i = 0; i < q; ++i) {
        long double k_z = l / 2.0 * (1 - cos(2.0 * PI * e[i] / t));
        long double k_y = -l / 2.0 * sin(2.0 * PI * e[i] / t);

        long double res = atan(k_z / sqrt(x * x + (k_y - y) * (k_y - y))) * 180.0 / PI;
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}
