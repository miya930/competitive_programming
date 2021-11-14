#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int cc = 2*c;
    int ans = 0;
    if (a+b > cc) {
        if (x < y) {
            ans += x * cc;
            y -= x;
            if (b > cc) ans += y * cc;
            else ans += y * b;
        } else {
            ans += y * cc;
            x -= y;
            if (a > cc) ans += x * cc;
            else ans += x * a;
        }
    } else {
        ans += (a*x+b*y);
    }
    cout << ans << endl;
}
