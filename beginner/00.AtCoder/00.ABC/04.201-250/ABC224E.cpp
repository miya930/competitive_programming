#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    map<int, vector<P>> mp;
    map<P, int> cell;
    for (int i = 0; i < n; ++i) {
        int r, c, a;
        cin >> r >> c >> a;
        mp[-a].emplace_back(P(r, c));
        cell[P(r, c)] = i;
    }

    vector<int> ans(n);
    map<int, int> mxr, mxc;
    for (auto [_,ps] : mp) {
        for (auto [r, c] : ps) {
            int now = max(mxr[r], mxc[c]);
            ans[cell[P(r, c)]] = now;
        }
        for (auto [r, c] : ps) {
            int now = ans[cell[P(r, c)]];
            chmax(mxr[r], now+1);
            chmax(mxc[c], now+1);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
