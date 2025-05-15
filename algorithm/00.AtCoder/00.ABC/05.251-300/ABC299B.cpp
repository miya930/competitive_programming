#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    map<int, priority_queue<pair<int,int>>> mp;

    for (int i = 0; i < n; i++) {
        mp[c[i]].push(make_pair(r[i], i+1));
    }

    if (mp.find(t) != mp.end()) {
        cout << mp[t].top().second << endl;;
    } else {
        cout << mp[c[0]].top().second << endl;
    }

    return 0;
}
