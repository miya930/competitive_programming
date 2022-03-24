#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[510][510];

int main()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }

    for (int i = 1; i < n+1; ++i) {
        for (int j = 2; j < n+1; ++j) cnt[i][j] += cnt[i][j-1];
    }

    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        int ans = 0;
        for (int l = p; l < q+1; ++l) ans += cnt[l][q];
        cout << ans << endl;
    }

    return 0;
}
