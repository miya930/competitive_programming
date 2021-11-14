#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        for (int j = 0; j < l[i]; ++j) {
            int t; cin >> t;
            a[i].push_back(t);
        }
    }

    map<vector<int>, int> cnt;

    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    int ans = 0;
    
    cout << cnt.size() << endl;
    
    return 0;
}
