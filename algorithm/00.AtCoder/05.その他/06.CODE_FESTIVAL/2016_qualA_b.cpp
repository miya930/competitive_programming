#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int to = a[i];
        if (i == a[to]) ans++;
    }

    cout << ans/2 << endl;
    return 0;
}
