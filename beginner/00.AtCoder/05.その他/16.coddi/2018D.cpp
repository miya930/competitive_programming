#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0;i < n; ++i) cin >> a[i];

    bool odd = false;
    for (int i = 0; i < n; ++i) {
        if (a[i]%2 == 1) odd = true;
    }

    if (odd) cout << "first" << endl;
    else cout << "second" << endl;

    return 0;
}
