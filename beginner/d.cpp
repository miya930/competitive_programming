#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int dx = {1, 0, -1, 0};
int dy = {0, 1, 0, -1};

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n);
    vector<pair<int,int> > a(n);

    map<pair<int, int>, int> mp, mpi;

    for (int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i] >> a[i].first;
        a[i].second = i;

        mp[make_pair(r[i], c[i])] = a[i];
        mpi[make_pair(r[i], c[i])] = i;
    }

    sort(a.begin(), a.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        int rt = r[a[i].second];
        int ct = c[a[i].second];
        int at = a[i].first;

        for (int j = 0; j < 4; ++j) {
            int nr = rt + dx[j];
            int nc = ct + dy[j];

            if (nr < 0 || nr >= h || nc < 0 || nc >= c) continue;

            int na = mp[make_pair(nr, nc)];
            int ni = mp[make_pair(nr, nc)];
            if (at < na) {
                ans[a[i].second] += ans[ni];
            }
        }

    }

    for (int i = 0; i < n; ++i) cout << ans[i] << endl;

    return 0;
}
