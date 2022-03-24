#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; ++i) cin >> r[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    cin >> Q;
    string ans = "";
    for (int q = 0; q < Q; ++q) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (r[a]+c[b] >= 6) ans += '#';
        else ans += '.';
    }
    cout << ans << endl;

    return 0;
}
