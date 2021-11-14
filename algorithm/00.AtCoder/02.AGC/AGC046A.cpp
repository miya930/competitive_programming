#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int gcd (int n, int m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int x; 
    cin >> x;

    int g = gcd(x, 360);

    cout << 360 / gcd(x, 360)  << endl;
    return 0;
}
