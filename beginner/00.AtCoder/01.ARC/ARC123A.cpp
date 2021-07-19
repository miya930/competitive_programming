#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long x = 2*b - a - c;
    if (x < 0) {
        if ((2*b)%2 == (a+c)%2) cout << -x / 2 << endl;
        else cout << -(x-1)/2 + 1 << endl;
    }
    else cout << x << endl;
}
