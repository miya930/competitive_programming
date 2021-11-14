#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll x, y, b;
    double a; 
    cin >> x >> y >> a >> b;

    ll ans = 0;
    while (y/a > x && x < (x+b)/a) {
        ans++;
        x *= (ll)a;
    }
    ans += (y-x-1) / b;
    cout << ans << endl;
}