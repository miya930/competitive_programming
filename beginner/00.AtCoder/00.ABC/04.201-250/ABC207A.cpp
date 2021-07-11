#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    ans = max(ans, a+b);
    ans = max(ans, b+c);
    ans = max(ans, a+c);
    cout << ans << endl;

}
