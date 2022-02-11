#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> sum(n, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        sum[a]++; sum[b]++;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (sum[i]%2 == 1) ok = false;
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
