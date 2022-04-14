#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> p;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) p.push_back({{b, a}, 0});
        else if (a > b) p.push_back({{a, b}, 1});
        else p.push_back({{a, a}, 2});
    }
    sort(p.begin(), p.end());

    int last = 0;
    int li = -1;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int b = p[i].first.first;
        int f = p[i].first.second;
        int di = p[i].second;

        if (li == -1) {
            last = b;
            li = di;
            ans++;
        } else if (di != li) {
            if (last >= f) continue;
            last = b;
            li = di;
            ans++;
        } else {
            if (last > f) continue;
            last = b;
            li = di;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
