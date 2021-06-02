#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000007;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = INF;

    for (int ab = 0; ab < 200100; ab++) {
        int sm = c * ab;

        int X = x - ab/2;
        int Y = y - ab/2;

        if (X > 0) sm += X*a;
        if (Y > 0) sm += Y*b;

        ans = min(ans, sm);
    }
    cout << ans << endl;
}
