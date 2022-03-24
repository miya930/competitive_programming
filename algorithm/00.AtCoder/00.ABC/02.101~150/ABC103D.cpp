#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vec(m);
    for (int i = 0; i < m; ++i) cin >> vec[i].second >> vec[i].first;

    sort(vec.begin(), vec.end());
    int last = -1, ans = 0;
    for (int i = 0; i < m; ++i) {
        if (last < vec[i].second) {
            ans++;
            last = vec[i].first-1;
        } 
    }

    cout << ans << endl;
    return 0;
}
