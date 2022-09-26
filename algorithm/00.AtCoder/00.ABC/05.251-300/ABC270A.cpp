#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;
    if ((a | b)&1) ans += 1;
    if (((a>>1)|(b>>1)) & 1) ans += 2;
    if (((a>>2)|(b>>2)) & 1) ans += 4; 

    cout << ans << endl;
    return 0;
}
