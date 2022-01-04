#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; ++q) {
        int x; cin >> x;

        int itr = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << n - itr << endl;
    }

    return 0;
}
