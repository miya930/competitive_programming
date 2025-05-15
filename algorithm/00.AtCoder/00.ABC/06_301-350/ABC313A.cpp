#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    int ma = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ma < p[i]) {
            ma = p[i];
        }
    }

    if (ma == p[0]) {
        for (int i = 0; i < n; i++) {
            if (p[i] == ma) cnt++;
        }
        if (cnt == 1) cout << 0 << endl;
        else cout << 1 << endl;
    } else cout << (ma + 1 - p[0]) << endl;

    return 0;
}
