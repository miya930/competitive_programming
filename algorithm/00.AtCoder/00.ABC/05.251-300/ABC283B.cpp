#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t, k;
        cin >> t >> k;
        k--;
        if (t == 1) {
            int x;
            cin >> x;
            a[k] = x;
        } else {
            cout << a[k] << endl;
        }
    }

    return 0;
}
