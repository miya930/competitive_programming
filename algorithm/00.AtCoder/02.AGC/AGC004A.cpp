#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans;
    if ((a%2==0) || (b%2==0) || (c%2==0)) {
        ans = 0;
    } else {
        ans = min(a*b, b*c);
        ans = min(ans, a*c);
    }

    cout << ans << endl;
    return 0;
}