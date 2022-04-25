#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> sim = a;
    vector<int> b(n);

    for (int kk = 0; kk < k; ++kk) {
        b.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            int l = max(0, i-sim[i]);
            int r = min(n-1, i+sim[i]);

            b[l]++;
            if (r+1 < n) b[r+1]--;
        }
        for (int i = 1; i < n; ++i) b[i] += b[i-1];
        sim = b;

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (b[i] != n) flag = false;
        }

        if (flag) break;
    }

    for (int i = 0; i < n; ++i) cout << b[i] << " ";
    return 0;
}
