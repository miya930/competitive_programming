#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k, Q;
    cin >> n >> k >> Q;

    vector<int> a(k), l(Q);

    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < Q; ++i) {
        cin >> l[i];
        l[i]--;
    }

    for (int q = 0; q < Q; ++q) {
        if (a[l[q]] == n) continue;
        else {
            if (a[l[q]]+1 == a[l[q]+1]) continue;
            a[l[q]]++;
        }
    }

    for (int i = 0; i < k; ++i) cout << a[i] << " ";
    cout << endl;

    return 0;
}
