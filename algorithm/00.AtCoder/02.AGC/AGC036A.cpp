#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    ll s;
    cin >> s;

    ll x2, y2, x3, y3;
    x2 = 1000000000; y2 = 1;
    x3 = (x2 - s%x2) % x2;
    y3 = (s+x3) / x2;
    
    cout << 0 << " " << 0 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;

}
