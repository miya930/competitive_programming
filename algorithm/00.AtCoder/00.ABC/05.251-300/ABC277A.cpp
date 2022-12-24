#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int ans;
    for (int i = 0; i < n; ++i) {
        if (p[i] == x) ans = i;
    }

    cout << ans+1 << endl;

    return 0;
}
