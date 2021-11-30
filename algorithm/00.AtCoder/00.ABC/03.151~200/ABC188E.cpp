#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
const int inf = 1001001001;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int,int>> score(n+1, make_pair(inf, -1));
    Graph G(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }

    for (int i = 0; i < n; ++i) {
        if (score[i].first == inf) {
            score[i].first = a[i];
            score[i].second = i;
        }

        for (auto nv : G[i]) {
            if (chmin(score[nv].first, a[i])) score[nv].second = score[i].second;
            if (chmin(score[nv].first, score[i].first)) score[nv].second = score[i].second;
        }
    }

    int ans = -inf;
    for (int i = 0; i < n; ++i) {
        if (i != score[i].second) {
            int temp = a[i] - score[i].first;
            ans = max(ans, temp);
        }
    }
    
    cout << ans << endl;
    return 0;
}
