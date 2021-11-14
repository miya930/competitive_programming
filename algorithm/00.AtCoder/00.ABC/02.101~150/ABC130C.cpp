#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    long double w, h, x, y;
    cin >> w >> h >> x >> y;

    cout << fixed << setprecision(10) << w * h / 2 << " ";
    if (x == w / 2 && y == h / 2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
