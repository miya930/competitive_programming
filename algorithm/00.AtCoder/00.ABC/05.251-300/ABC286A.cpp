#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    p--; q--; r--; s--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = p; i <= q; i++) {
        int j = r + i - p;
        swap(a[i], a[j]);
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
