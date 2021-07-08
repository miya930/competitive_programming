#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int r, g, b, n;
    cin >> r >> b >> g >> n;

    long long ans = 0;
    for (int i = 0; i <= n/r; ++i) {
        for (int j = 0; j <= n/g; ++j) {
            int res = n - r*i - g*j;
            if ((res >= 0) && (res%b == 0)) ans++;
        }
    }
    cout << ans << endl;
}
