// bit全探索
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int m; cin >> m;

        bool ok = false;
        for (int bit = 0; bit < 1<<n; ++bit) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (bit>>i & 1) {
                    sum += a[i];
                }
            }
            if (sum == m) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
