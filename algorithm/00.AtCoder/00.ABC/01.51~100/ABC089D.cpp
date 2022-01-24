#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    map<int, pair<int,int>> mp;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            mp[a[i][j]] = {i, j};
        }
    }

    vector<int> cost(h*w+1, -1);
    for (int i = h*w; i > 0; --i) {
        if (cost[i] != -1) continue;
        cost[i] = 0;
        int tmp = i;
        while(tmp-d > 0) {
            int nx = mp[tmp].first;
            int ny = mp[tmp].second;
            int x  = mp[tmp-d].first;
            int y  = mp[tmp-d].second;
            int diffx = abs(nx-x);
            int diffy = abs(ny-y);
            cost[tmp-d] = cost[tmp] + diffx + diffy;
            tmp -= d;
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << cost[l] - cost[r] << endl;
    }
    return 0;
}
