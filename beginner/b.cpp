#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((b - d*c) >= 0) {
        cout << -1 << endl;
        return 0;
    }

    long long ans = 0;
    while ((a+ans*b) > d*c*ans) {
        ans++;
    }
    cout << ans << endl;
}
