#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int ans = 1;
    for (int i = 0;  i< n; ++i) {
        ans *= 2;
    }

    cout << ans << endl;
    return 0;
}
