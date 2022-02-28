#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll h, w, C, Q;
    cin >> h >> w >> C >> Q;

    vector<ll> cnt(C, 0);
    map<int,int> row, col;
    for (int i = 0; i < Q; ++i) {
        row[i] = 0;
        col[i] = 0;
    }
    ll rowcnt = 0, colcnt = 0;

    vector<ll> t(Q), n(Q), c(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> t[i] >> n[i] >> c[i];
        n[i]--; c[i]--;
    }

    for (int i = Q-1; i >= 0; --i) {

        if (t[i] == 1) {
            if (row[n[i]] != 0) continue;
            rowcnt++;

            cnt[c[i]] += (w-colcnt);
            row[n[i]]++;

        } else {
            if (col[n[i]] != 0) continue;
            colcnt++;

            cnt[c[i]] += (h-rowcnt);
            col[n[i]]++;
        }
    }
    
    for (int i = 0; i < C; ++i) cout << cnt[i] << " ";
    cout << endl;

    return 0;
}
