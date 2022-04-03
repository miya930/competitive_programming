#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 1;
    ll odd = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i]%2 == 0) odd *= 2;
        ans *= 3;
    }

    cout << ans - odd << endl;
    return 0;
}
