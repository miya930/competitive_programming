#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q), x(q);
    for (int i = 0; i < q; ++i) cin >> l[i] >> r[i] >> x[i];

    vector<ll> sum(n+100, 0);
    for (int i = 0; i < q; ++i) {
        sum[l[i]] += x[i];
        sum[r[i]+1] -= x[i];
    }

    for (int i = 2; i <= n; ++i) {
        if (sum[i] > 0) cout << "<";
        else if (sum[i]==0) cout << "=";
        else cout << ">";
    }
    cout << endl;

    return 0;
}
