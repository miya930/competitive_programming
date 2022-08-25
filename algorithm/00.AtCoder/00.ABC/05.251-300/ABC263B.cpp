#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 2; i <= n; ++i) cin >> p[i];

    int cur = n;
    int ans = 0;
    while(1) {
        int t = p[cur];
        ans++;

        if (t == 1) break;
        else cur = t;
    }

    cout << ans << endl;

    return 0;
}
