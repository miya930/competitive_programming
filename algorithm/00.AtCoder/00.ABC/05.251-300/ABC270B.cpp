#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    if (0 < y && y < x) {
        if (y < z) {
            cout << -1 << endl;
        } else {
            cout << abs(z-0) + abs(x-z) << endl;
        }
    } else if (x < y && y < 0) {
        if ( z < y) {
            cout << -1 << endl;
        } else {
            cout << abs(z-0) + abs(x-z) << endl;
        }
    } else {
        cout << abs(x) << endl;
    }


    return 0;
}
